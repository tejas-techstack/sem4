import socket
import threading
import time


def tcp_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 12345))
    server_socket.listen(1)
    print("TCP Server listening on port 12345...")
    
    conn, addr = server_socket.accept()
    print(f"Connected by {addr}")
    data = conn.recv(1024)
    print(f"Received: {data.decode()}")
    conn.sendall(b'Hello from TCP server')
    conn.close()

tcp_server_thread = threading.Thread(target=tcp_server)
tcp_server_thread.start()
time.sleep(1)
tcp_server_thread.join()
