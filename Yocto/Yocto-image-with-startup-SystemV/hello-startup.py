import datetime

print("Hello from python")
now_=datetime.datetime.now()
fd=open("/etc/diploma-version","w+")
fd.write(str(now_))
fd.close()