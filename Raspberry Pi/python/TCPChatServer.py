from socket import *

host = "100.100.100.42"
port = 12345

s = socket(AF_INET,SOCK_STREAM)
s.bind((host,port))

s.listen(1) #number of client to accept
print("Listening for Connection: ", host)
conn = None

while True:
    if conn is None:
        print('Waiting: ')
        conn,addr = s.accept()
        print("Connection form ", addr)
    else:
        print(conn.recv(1024))
        conn.send(b'OK')
    
conn.close()