import subprocess
import os

os.chdir('/Users/yee/Code/C')
print(os.getcwd())

shellcode = "\x12\x34\x56\x78"
prob = ["1", "2", "3", "4", "5"]

p = subprocess.Popen(
        ["./return.out", shellcode] + prob, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    )

try:
    p.wait(1)
    returncode = p.poll()
    if returncode is None:
        print("TIMEOUT!")
        exit()

except Exception as E:
    print("something wrong!")
    print(E)
    exit()

print(returncode)