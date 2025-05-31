import hashlib
import json
import time

def compute_block_hash(block):
    """
    Computes SHA-256 over the block’s content (excluding 'hash').
    Content includes: index, previousHash, transaction, timestamp, etc.
    """
    temp = dict(block)            # make a shallow copy
    temp.pop("hash", None)        # remove existing hash before re-hashing
    block_str = json.dumps(temp, sort_keys=True)
    return hashlib.sha256(block_str.encode()).hexdigest()

def create_block(index, previous_hash, transaction):
    """
    Creates a new block in our chain. Each block holds exactly ONE transaction.
    'previous_hash' links this block to the one before it, forming a chain.
    'transaction' is a dict describing 'CREATE' or 'PAY'.
    """
    block = {
        "index": index,
        "timestamp": time.time(),
        "transaction": transaction,   # { type, sender, receiver, amount, etc. }
        "previousHash": previous_hash
    }
    block["hash"] = compute_block_hash(block)
    return block

def verify_block(block):
    """
    Re-computes the hash and checks if it matches block['hash'].
    Returns True if unchanged; False if tampered.
    """
    recalculated = compute_block_hash(block)
    return (recalculated == block["hash"])

def verify_chain(blockchain):
    """
    Verifies that:
    1) Each block's 'hash' matches the data inside it.
    2) Each block's 'previousHash' matches the actual 'hash' of the block before it.
    Returns True if the chain is fully valid; False otherwise.
    """
    for i in range(len(blockchain)):
        current_block = blockchain[i]
        
        # Check self-consistency
        if not verify_block(current_block):
            print(f"Block {i} is tampered (hash mismatch).")
            return False
        
        # Check link to previous block (except for genesis block)
        if i > 0:
            prev_block = blockchain[i - 1]
            if current_block["previousHash"] != prev_block["hash"]:
                print(f"Block {i} has a wrong previousHash link!")
                return False
    
    return True

#------------------------- GOOFY COIN TRANSACTIONS -------------------------
def create_transaction(tx_type, sender, receiver, amount):
    """
    Creates a transaction dictionary: type is either 'CREATE' or 'PAY'.
    - 'CREATE': sender='SYSTEM', receiver='Alice' (for example).
    - 'PAY': sender='Alice', receiver='Bob', etc.
    - 'amount': how many coins.
    """
    return {
        "type": tx_type,
        "sender": sender,
        "receiver": receiver,
        "amount": amount
    }

def get_balance(blockchain, user):
    """
    Scans the entire chain, computing 'user' balance by looking at each block’s transaction.
    - For 'CREATE', user’s balance increases if user == receiver.
    - For 'PAY', user’s balance decreases if user == sender, increases if user == receiver.
    """
    balance = 0
    for block in blockchain:
        tx = block["transaction"]
        if tx["type"] == "CREATE":
            if tx["receiver"] == user:
                balance += tx["amount"]
        elif tx["type"] == "PAY":
            if tx["sender"] == user:
                balance -= tx["amount"]
            if tx["receiver"] == user:
                balance += tx["amount"]
    return balance

def can_pay(blockchain, sender, amount):
    """
    Returns True if 'sender' has enough coins for 'amount'.
    """
    return get_balance(blockchain, sender) >= amount

# ================ DEMO: A -> Server -> B -> Server -> A =================
if __name__ == "__main__":

    # --- 1. CLIENT A CREATES GENESIS BLOCK (Data1) ---
    # Suppose 'Data1' is a CREATE transaction awarding 10 coins to Alice.
    
    genesis_transaction = create_transaction(tx_type="CREATE", 
                                             sender="SYSTEM", 
                                             receiver="Alice", 
                                             amount=10)
    genesis_block = create_block(index=0, previous_hash=None, 
                                 transaction=genesis_transaction)
    blockchain = [genesis_block]

    # Next, A adds a second block (Data2), e.g., CREATE 5 coins for Bob
    tx2 = create_transaction("CREATE", "SYSTEM", "Bob", 5)
    block2 = create_block(index=1, previous_hash=blockchain[-1]["hash"], 
                          transaction=tx2)
    blockchain.append(block2)
    
    print("\nClient A -> Server (Chain with Data1 & Data2):")
    for b in blockchain:
        print(json.dumps(b, indent=2))
    print("Is chain valid?", verify_chain(blockchain))
    print("Balances: Alice =", get_balance(blockchain, "Alice"),
          ", Bob =", get_balance(blockchain, "Bob"), "\n")
    
    # --- 2. SERVER -> CLIENT B ---
    # B sees the chain and decides to create Data3: PAY from Bob -> Alice of 3 coins
    # (But only if Bob has enough.)
    if can_pay(blockchain, "Bob", 3):
        tx3 = create_transaction("PAY", "Bob", "Alice", 3)
        block3 = create_block(index=2, previous_hash=blockchain[-1]["hash"], 
                              transaction=tx3)
        blockchain.append(block3)
        print("Client B adds Data3 (Bob pays 3 to Alice) -> Server -> A:")
        for b in blockchain:
            print(json.dumps(b, indent=2))
        print("Is chain valid?", verify_chain(blockchain))
        print("Balances: Alice =", get_balance(blockchain, "Alice"),
              ", Bob =", get_balance(blockchain, "Bob"))
    else:
        print("Bob cannot pay 3 coins (insufficient balance).")
    
    # --- 3. A final check (Client A receives the updated chain) ---
    final_check = verify_chain(blockchain)
    print("\nClient A final chain verification:", final_check, "\n")
    
    # Show tampering
    print("Tampering with block2 to give Bob 999 coins instead of 5...")
    blockchain[0]["transaction"]["amount"] = 999

    print("Is chain still valid after tampering?", verify_chain(blockchain))
    print("Balances after tampering (if ignoring chain validity):",
          "Alice =", get_balance(blockchain, "Alice"),
          ", Bob =", get_balance(blockchain, "Bob"))
