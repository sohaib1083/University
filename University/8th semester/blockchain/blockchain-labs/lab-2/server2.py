import socket

HOST = "127.0.0.1"
PORT = 5002  # Change for Server-3 if needed

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"[SERVER 2] Listening on {HOST}:{PORT}")

    while True:
        conn, addr = server.accept()
        data = conn.recv(1024).decode()
        print(f"[SERVER 2] Forwarding to Validator...")

        # Forward to Server-1 for validation
        validator_host, validator_port = "127.0.0.1", 5001
        validator = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        validator.connect((validator_host, validator_port))
        validator.send(data.encode())

        response = validator.recv(1024).decode()
        print(f"[SERVER 2] Validator Response: {response}")

        conn.send(response.encode())
        validator.close()

start_server()
