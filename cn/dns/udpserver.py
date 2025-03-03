import socket
import threading
import time

def udp_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 12346))
    print("UDP Server listening on port 12346...")
    
    data, addr = server_socket.recvfrom(1024)
    print(f"Received from {addr}: {data.decode()}")
    server_socket.sendto(b'Hello from UDP server', addr)
    
udp_server_thread = threading.Thread(target=udp_server)
udp_server_thread.start()
time.sleep(1)
udp_server_thread.join()
