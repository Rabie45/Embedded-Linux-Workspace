# Raspberrypi-PWM-
PWM (Pulse Width Modulation) on the Raspberry Pi allows you to control the intensity of GPIO pins by varying the duty cycle of the signal. This is commonly used for tasks like controlling the brightness of LEDs, the speed of motors, or generating analog-like output.
## First 
 - connect with raspberry pi through ssh
 - ``` ssh pi@<YOUR-IP>```
 - Write your python script given in the repo
 - Transport the file via ssh py this line
 - ``` scp pwm.py pi@<YOUR-IP>:/home/pi ```
 - you would find the file in /home/pi
 - run the script using ``` python3 pwm.py```

   



https://github.com/Rabie45/Raspberrypi-PWM-/assets/76526170/5b6d2f85-033b-499b-af5e-74579ea67bb4

