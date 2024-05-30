import RPi.GPIO as gpio

gpio.setmode(gpio.BCM)  # 15
gpio.setup(21, gpio.OUT)
while True:
    x= input("pleas enter the value: ")
    if x=="ON" or x == "on":
        gpio.output(21,gpio.HIGH)
    else:
        gpio.output(21,gpio.LOW)