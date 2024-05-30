import RPi.GPIO as gpio
from time import sleep

pin=12
gpio.setmode(gpio.BCM)
gpio.setup(pin,gpio.OUT)

piPwm=gpio.PWM(pin,100)
piPwm.start(0)
while True:
    for duty in range(0,101,1):
        piPwm.ChangeDutyCycle(duty)
        sleep(0.1)
    sleep(0.5)
    for duty in range(100,-1,-1):
        piPwm.ChangeDutyCycle(duty)
        sleep(0.1)
    sleep(0.5)
