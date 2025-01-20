import socket

HOST = '127.0.0.1'  # Replace with server IP if remote
PORT = 8080         # Replace with your server port

try:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        print("Connected to the server")
        data = s.recv(1024)  # Receive data from server
        print("Received:", data.decode())
except Exception as e:
    print("Connection failed:", e)
