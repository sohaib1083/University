import socket
import json
import hashlib

SERVER_HOST = "127.0.0.1"
SERVER_PORT = 5002  # Connects to Server-2

def generate_client_hash(client_id):
    """Generate a unique hash for the client."""
    return hashlib.sha256(client_id.encode()).hexdigest()

def send_transaction(client_id, message):
    """Send a transaction to the server."""
    transaction = {
        "client_hash": generate_client_hash(client_id),
        "message": message
    }

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((SERVER_HOST, SERVER_PORT))
    client.send(json.dumps(transaction).encode())

    response = client.recv(1024).decode()
    print(f"[CLIENT {client_id}] Server Response: {response}")
    client.close()

# Example Usage
send_transaction("Client-1", "Hello from Client-1 -- 2nd message")
