import socket
import threading
import time

# TCP Client
def tcp_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))
    client_socket.sendall(b'Hello from TCP client')
    data = client_socket.recv(1024)
    print(f"Received: {data.decode()}")
    client_socket.close()

tcp_client()
