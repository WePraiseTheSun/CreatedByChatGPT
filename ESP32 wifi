import network
import time
import usocket

class WiFiManager:
    def __init__(self, ssid, password):
        self.ssid = ssid
        self.password = password
        self.station = network.WLAN(network.STA_IF)
    
    def connect(self):
        self.station.active(True)
        self.station.connect(self.ssid, self.password)

        while not self.station.isconnected():
            pass

        print('Connection successful')
        print(self.station.ifconfig())

class HTTPClient:
    def __init__(self):
        pass
    
    def get(self, url):
        try:
            proto, dummy, host, path = url.split('/', 3)
        except ValueError:
            proto, dummy, host = url.split('/', 2)
            path = ''
        if not path:
            path = ''
        addr = usocket.getaddrinfo(host, 80)[0][-1]
        s = usocket.socket()
        s.connect(addr)
        s.send(bytes('GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n' % (path, host), 'utf8'))

        while True:
            data = s.recv(100)
            if data:
                print(str(data, 'utf8'), end='')
            else:
                break
        s.close()
    
    def post(self, url, payload):
        try:
            proto, dummy, host, path = url.split('/', 3)
        except ValueError:
            proto, dummy, host = url.split('/', 2)
            path = ''
        if not path:
            path = ''
        addr = usocket.getaddrinfo(host, 80)[0][-1]
        s = usocket.socket()
        s.connect(addr)
        s.send(bytes('POST /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %d\r\n\r\n%s' % (path, host, len(payload), payload), 'utf8'))

        while True:
            data = s.recv(100)
            if data:
                print(str(data, 'utf8'), end='')
            else:
                break
        s.close()

# Usage Example
ssid = 'xxx'
password = 'xxx'
wifi = WiFiManager(ssid, password)
wifi.connect()

http_client = HTTPClient()
http_client.get('http://www.example.com')
http_client.post('http://www.example.com/post', 'key1=value1&key2=value2')

