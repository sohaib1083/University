import json
import hashlib
import os

class Node:
    def __init__(self, transaction_data, previous_hash):
        self.transaction_data = transaction_data
        self.previous_hash = previous_hash
        self.hash = self.compute_hash()
        self.next = None

    def compute_hash(self):
        transaction_string = json.dumps(self.transaction_data, sort_keys=True)
        return hashlib.sha256(transaction_string.encode()).hexdigest()

class Ledger:
    def __init__(self):
        self.head = None
        self.load_ledger()

    def add_transaction(self, transaction):
        if self.head is None:
            new_node = Node(transaction, "GENESIS")
        else:
            new_node = Node(transaction, self.head.hash)
            new_node.next = self.head
        self.head = new_node
        self.save_ledger()

    def save_ledger(self):
        ledger_data = []
        current = self.head
        while current:
            ledger_data.append({
                "transaction_data": current.transaction_data,
                "hash": current.hash,
                "previous_hash": current.previous_hash
            })
            current = current.next
        with open("ledger.json", "w") as file:
            json.dump(ledger_data, file, indent=4)

    def load_ledger(self):
        """Handles missing or empty ledger.json."""
        if not os.path.exists("ledger.json"):
            print("🔹 No existing ledger found. Creating a new one...")
            return  # No file, so we start fresh

        try:
            with open("ledger.json", "r") as file:
                ledger_data = json.load(file)
                if not ledger_data:  # Handle empty file
                    print("⚠️ Ledger file was empty. Starting fresh...")
                    return
                for data in reversed(ledger_data):
                    self.add_transaction(data["transaction_data"])
        except json.JSONDecodeError:
            print("⚠️ Ledger file is corrupted. Starting fresh...")
