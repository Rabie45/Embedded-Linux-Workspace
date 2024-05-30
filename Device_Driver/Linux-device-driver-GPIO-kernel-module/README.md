# Kernel-module-GPIO
A kernel module for GPIO (General Purpose Input/Output) is a piece of code that runs in the Linux kernel space, allowing the kernel to interact with the GPIO pins.

## Commands 

 - Move the module file and the Makefile to the raspberrypi
 - Install the headers for rasp kernel ```sudo apt install raspberrypi-kernel-headers```
 - ``` sudo scp Makefile pi@192.168.1.17:/home/pi```
 - ``` sudo scp hello.c pi@192.168.1.17:/home/pi```
 - Then go to raspbery pi and ``` make```
 - Them insert module to the kernel ```sudo insmod hello.ko```
 - change the peremssion of the file created to the usersapce ```sudo chmod 777 /dev/test_file```
 - write the value to the pin number ```echo 1 > /dev/test_file```   to Gpio on
 - write the value to the pin number ```echo 0 > /dev/test_file```   to Gpio off                                                
