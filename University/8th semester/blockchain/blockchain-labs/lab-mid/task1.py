import hashlib
import time
import random
import threading
import socket

# Define blockchain parameters
difficulty = 5  # Increase difficulty for more nonce variation
miners = ["Miner A", "Miner B", "Miner C", "Miner D", "Miner E", "Miner F"]
transactions = ["Alice sends 5 BTC to Bob"]
prev_hash = "000000abcd1234"  # Previous block hash
blockchain = []  # Store confirmed blocks
miner_profits = {miner: 0 for miner in miners}  # Track miner earnings

# Simulating Alice's Private/Public Key Pair (For Signature Verification)
alice_private_key = "alice_private_key_123"
alice_public_key = "alice_public_key_456"

# Shared variables
winner_found = False
winning_miner = None
winning_nonce = None
winning_hash = None

# Function to compute hash with nonce
def compute_hash(block_data, nonce):
    data = f"{block_data}{nonce}".encode()
    return hashlib.sha256(data).hexdigest()

# Simulating Alice's Digital Signature (Hashing the transaction with a secret key)
def sign_transaction(transaction, private_key):
    return hashlib.sha256(f"{transaction}{private_key}".encode()).hexdigest()

# Simulating Verification of Alice's Signature (Using Alice's Public Key)
def verify_signature(transaction, signature, public_key):
    expected_signature = hashlib.sha256(f"{transaction}{alice_private_key}".encode()).hexdigest()
    return signature == expected_signature

# Mining function for each client (running on different ports)
def miner_node(miner_name, port):
    global winner_found, winning_nonce, winning_miner, winning_hash
    nonce = random.randint(10000, 999999)  # Increase range for more randomness
    start_time = time.time()
    transaction = transactions[0]  # Alice's transaction

    # Alice signs the transaction before it enters the block
    alice_signature = sign_transaction(transaction, alice_private_key)

    while not winner_found:  # Stop mining once a winner is found
        block_data = f"{prev_hash}{transaction}{alice_signature}{random.randint(1,1000)}"  # More randomness
        block_hash = compute_hash(block_data, nonce)

        # Task 2: Simulate a miner trying to send a fake nonce (should fail verification)
        if random.random() < 0.1:  # 10% chance to send an invalid nonce
            fake_nonce = nonce + 99999  # Hardcoded invalid nonce
            fake_block_hash = compute_hash(block_data, fake_nonce)
            if fake_block_hash[:difficulty] == "0" * difficulty:
                print(f"Miner {miner_name} tried submitting a FAKE NONCE! Rejected!")

        # Check if the hash meets the difficulty requirement (starts with '00000')
        if block_hash[:difficulty] == "0" * difficulty:
            winner_found = True  # Stop all other miners
            winning_nonce = nonce  # Store the winning nonce
            winning_miner = miner_name  # Store winning miner
            winning_hash = block_hash  # Store winning hash
            end_time = time.time()

            print(f"\nSTEP 1: {miner_name} found the valid nonce first!")
            print(f"Winning Nonce: {winning_nonce}")

            # Verify Alice's Transaction Signature
            if verify_signature(transaction, alice_signature, alice_public_key):
                print("STEP 2: Alice's transaction signature is VERIFIED!")

                # Add to Blockchain
                blockchain.append({
                    "miner": miner_name,
                    "nonce": nonce,
                    "block_hash": block_hash,
                    "transaction": transaction,
                    "signature_verified": True
                })
                print(f"STEP 3: Block added to Blockchain by {miner_name}!")

                # Miner gets profit for mining the block
                miner_profits[miner_name] += 10  # 10 BTC reward
                print(f"Miner {miner_name} earned 10 BTC! Total Profit: {miner_profits[miner_name]} BTC")

                # Simulate broadcasting the block
                result = f"\nWINNER: {miner_name} (Port {port})\nNonce: {nonce}\nHash: {block_hash}\nTime Taken: {round(end_time - start_time, 2)}s\n"
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
                    client_socket.connect(("localhost", 5000))
                    client_socket.sendall(result.encode())

                print("STEP 4: Block BROADCASTED to the network!\n")

            break  # Exit loop after finding a valid block

        nonce += random.randint(1, 1000)  # Increase randomness to make nonce different each run

# Simulated Blockchain Server (listens for mined blocks and verifies them)
def blockchain_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # Fix address in use error
        server_socket.bind(("localhost", 5000))
        server_socket.listen(len(miners))
        print("Blockchain Server is running and listening for mined blocks...\n")

        while True:
            conn, addr = server_socket.accept()
            with conn:
                data = conn.recv(1024).decode()
                if data:
                    print(f"STEP 4: BROADCASTED BLOCK:\n{data}")
                    break  # Stop server once winner is found

# Start blockchain server in a separate thread
server_thread = threading.Thread(target=blockchain_server, daemon=True)
server_thread.start()

# Start mining clients on different ports
threads = []
for i, miner in enumerate(miners):
    port = 5001 + i  # Assign a unique port to each miner
    miner_thread = threading.Thread(target=miner_node, args=(miner, port))
    threads.append(miner_thread)
    miner_thread.start()

# Wait for all miners to finish
for thread in threads:
    thread.join()

# Final Verification Step
print("\nSTEP 5: Final Blockchain Verification:")
for block in blockchain:
    if block["signature_verified"] and block["nonce"] == winning_nonce:
        print(f"✅ Block Mined by {block['miner']} is Valid!")
    else:
        print(f"❌ Block Mined by {block['miner']} is INVALID (Rejected)!")

# Print miner profits
print("\nMiner Profits:")
for miner, profit in miner_profits.items():
    print(f"{miner}: {profit} BTC")

print("\nSimulation complete. Only one valid block was mined.")
