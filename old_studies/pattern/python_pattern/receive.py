import socket


while True:
    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client.connect(('localhost',2401))
    print('received:{0}'.format(client.recv(2401)))
    client.close()
