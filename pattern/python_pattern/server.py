import socket

for i in (2401, 2402, 2403, 2404, 2405):
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', i))
    server.close()


def respond(client):
    response = raw_input("Enter a value:")
    client.send(bytes(response))
    client.close()


class LogSocket:

    def __init__(self, socket):
        self.socket = socket

    def send(self, data):
        print('sending {0} to {1}'.format(data,
                                          self.socket.getpeername()[0]))
        self.socket.send(data)

    def close(self):
        self.socket.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('localhost', 2401))
server.listen(1)
try:
    while True:
        client, addr = server.accept()
        respond(LogSocket(client))
finally:
    server.close()
