import hashlib
import json

def compute_tx_hash(tx):
    """Compute SHA-256 hash of a transaction’s data (excluding 'hash')."""
    temp = dict(tx)
    temp.pop("hash", None)
    tx_string = json.dumps(temp, sort_keys=True)
    return hashlib.sha256(tx_string.encode()).hexdigest()

def create_transaction(tx_id, tx_type, sender, receiver, amount):
    """
    Create a transaction dict with fields:
      - txID, tx_type (CREATE or PAY), sender, receiver, amount, hash
    """
    tx = {
        "txID": tx_id,
        "type": tx_type,
        "sender": sender,
        "receiver": receiver,
        "amount": amount
    }
    tx["hash"] = compute_tx_hash(tx)
    return tx

def verify_transaction(tx):
    """Re-compute the transaction hash and compare."""
    return tx["hash"] == compute_tx_hash(tx)

def verify_ledger(ledger):
    """
    Check that every transaction in the ledger is intact (not tampered).
    This does *not* check for double spending or balances—it’s only a hash check.
    """
    for tx in ledger:
        if not verify_transaction(tx):
            return False
    return True

def get_balance(ledger, user):
    """
    Calculate how many coins 'user' has by summing over CREATE and PAY transactions.
      - CREATE: 'receiver' gains coins.
      - PAY: 'sender' loses coins, 'receiver' gains coins.
    """
    balance = 0
    for tx in ledger:
        if tx["type"] == "CREATE":
            if tx["receiver"] == user:
                balance += tx["amount"]
        elif tx["type"] == "PAY":
            if tx["sender"] == user:
                balance -= tx["amount"]
            if tx["receiver"] == user:
                balance += tx["amount"]
    return balance

# --------------- DEMO: The Double-Spend Problem ---------------
if __name__ == "__main__":

    ledger = []
    # Step 1: System creates 10 coins for Bob
    tx1 = create_transaction(tx_id=1, tx_type="CREATE", sender="SYSTEM", receiver="Bob", amount=10)
    ledger.append(tx1)
    
    print("\nInitial Ledger (Bob has 10 coins):")
    print(json.dumps(ledger, indent=2))
    print("Balances -> Bob =", get_balance(ledger, "Bob"), "\n")

    # Step 2: Bob tries to pay Alice 10 coins
    tx2 = create_transaction(tx_id=2, tx_type="PAY", sender="Bob", receiver="Alice", amount=10)
    ledger.append(tx2)
    
    # Step 3: Bob *also* tries to pay Charlie 10 coins (same 10!)
    tx3 = create_transaction(tx_id=3, tx_type="PAY", sender="Bob", receiver="Charlie", amount=10)
    ledger.append(tx3)

    print("Ledger after Bob’s two payments:")
    print(json.dumps(ledger, indent=2))
    print("verify_ledger() =>", verify_ledger(ledger))
    
    # Notice we do *not* block the second payment. Let's see final balances:
    print("Final Balances:")
    print("  Bob =", get_balance(ledger, "Bob"))
    print("  Alice =", get_balance(ledger, "Alice"))
    print("  Charlie =", get_balance(ledger, "Charlie"))
    
    """
    In a real system, Bob cannot magically pay 10 coins *twice* if he only has 10 total.
    But this naive ledger doesn't check each transaction’s validity upon addition.
    It just appends them, letting Bob "double spend."
    """

def add_transaction(ledger, tx):
    """
    Safely add a transaction to the ledger if it’s valid.
    - For CREATE, no problem. 
    - For PAY, check sender's current balance in the ledger.
    Returns True if added successfully, False if rejected.
    """
    if tx["type"] == "CREATE":
        # Always allow coin creation from SYSTEM (assuming unlimited supply).
        ledger.append(tx)
        return True
    elif tx["type"] == "PAY":
        sender_balance = get_balance(ledger, tx["sender"])
        if sender_balance >= tx["amount"]:
            # Sender has enough coins, so we can accept this payment
            ledger.append(tx)
            return True
        else:
            print(f"Rejected transaction {tx['txID']}: insufficient funds for {tx['sender']}.")
            return False
    else:
        print(f"Unknown transaction type {tx['type']}.")
        return False

# Example usage in main:

ledger2 = []

# 1) CREATE 10 coins for Bob
tx1b = create_transaction(1, "CREATE", "SYSTEM", "Bob", 10)
add_transaction(ledger2, tx1b)

# 2) Bob tries to pay Alice 10 coins -> this should succeed
tx2b = create_transaction(2, "PAY", "Bob", "Alice", 10)
add_transaction(ledger2, tx2b)

# 3) Bob tries to pay Charlie 10 coins -> this should *fail* now
tx3b = create_transaction(3, "PAY", "Bob", "Charlie", 10)
result = add_transaction(ledger2, tx3b)

print("\nLedger2 after attempting Bob’s two payments:")
print(json.dumps(ledger2, indent=2))
print("Result of second payment attempt?", result)
print("Balances -> Bob =", get_balance(ledger2, "Bob"),
      ", Alice =", get_balance(ledger2, "Alice"),
      ", Charlie =", get_balance(ledger2, "Charlie"))
