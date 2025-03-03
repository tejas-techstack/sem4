import socket
import threading
import time

def udp_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.sendto(b'Hello from UDP client', ('localhost', 12346))
    data, addr = client_socket.recvfrom(1024)
    print(f"Received: {data.decode()}")


udp_client()
       
