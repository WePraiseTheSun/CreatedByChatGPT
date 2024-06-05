import network
import time
import usocket
import uselect

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

        poller = uselect.poll()
        poller.register(s, uselect.POLLIN)
        
        while True:
            events = poller.poll(1000)  # Wait for 1 second
            if events:
                data = s.recv(100)
                if data:
                    print(str(data, 'utf8'), end='')
                else:
                    break
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

        poller = uselect.poll()
        poller.register(s, uselect.POLLIN)
        
        while True:
            events = poller.poll(1000)  # Wait for 1 second
            if events:
                data = s.recv(100)
                if data:
                    print(str(data, 'utf8'), end='')
                else:
                    break
            else:
                break
        s.close()

def countdown(seconds):
    while seconds:
        print(f"Next request in {seconds} seconds", end='\r')
        time.sleep(1)
        seconds -= 1

# Usage Example
ssid = 'xxx'
password = 'xxx'
wifi = WiFiManager(ssid, password)
wifi.connect()

http_client = HTTPClient()

# Infinite loop to make GET requests every 10 seconds
while True:
    http_client.get('https://www.example.com')
    countdown(10)

