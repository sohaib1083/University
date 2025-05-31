import socket
import json
from ledger import Ledger

HOST = "127.0.0.1"
PORT = 5001  # Validator server
ledger = Ledger()

def verify_transaction(transaction):
    """Consensus mechanism to verify client transactions."""
    client_hash = transaction["client_hash"]
    
    # Check if this client has already sent the same transaction
    current = ledger.head
    while current:
        if current.transaction_data["client_hash"] == client_hash and \
           current.transaction_data["message"] == transaction["message"]:
            return False  # Duplicate transaction
        current = current.next
    return True  # New valid transaction

def print_shared_ledger():
    """Prints the ledger after every transaction."""
    current = ledger.head
    print("\n🔹🔹🔹 SHARED LEDGER 🔹🔹🔹")
    while current:
        print(f"📌 Client Hash: {current.transaction_data['client_hash']}")
        print(f"   📨 Message: {current.transaction_data['message']}")
        print(f"   🔗 Hash: {current.hash}")
        print(f"   ⬆️ Previous Hash: {current.previous_hash}")
        print("-" * 40)
        current = current.next
    print("🔹🔹🔹 END OF LEDGER 🔹🔹🔹\n")

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"[SERVER 1 - VALIDATOR] Listening on {HOST}:{PORT}")

    while True:
        conn, addr = server.accept()
        data = conn.recv(1024).decode()
        transaction = json.loads(data)

        # Verify transaction
        if verify_transaction(transaction):
            ledger.add_transaction(transaction)
            response = "✅ Transaction Approved & Stored"
        else:
            response = "❌ Transaction Rejected (Duplicate)"

        print(f"[SERVER 1] {response}")  # Print Approval Status
        print_shared_ledger()

        conn.send(response.encode())

start_server()
