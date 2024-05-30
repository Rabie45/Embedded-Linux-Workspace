# Raspberrypi-blink-led
To blink an LED on a Raspberry Pi using Python, you can use the GPIO library. Here's a simple example

This Python script sets up pin 21 as an output and then enters a loop where it turns the LED on, waits for one second, turns the LED off, and waits for another second. This creates a blinking effect when typing on or ON.
Before running this script, make sure you have the RPi.GPIO library installed on your Raspberry Pi. You can install it using pip if you haven't already:

## First 
 - connect with raspberry pi through ssh
 - ``` ssh pi@<YOUR-IP>```
 - Write your python script given in the repo
 - Transport the file via ssh py this line
 - ``` scp sr.py pi@<YOUR-IP>:/home/pi ```
 - you would find the file in /home/pi
 - execute the file by writing on or ON in the terminal 

https://github.com/Rabie45/Raspberrypi-blink-led/assets/76526170/8a1b15e6-0862-4f7f-92a4-790fa1a1eea3

