# Linux Kernel
The Linux kernel is the core component of the Linux operating system. It acts as a bridge between the hardware and the software layers, providing essential functionalities such as process management, memory management, device drivers, file system support, and networking capabilities.

## Steps
### Download
  - use https://www.kernel.org/
  -I will is longterm:	6.6.29	2024-04-27
![Screenshot_2024-04-29_14-30-43](https://github.com/Rabie45/Embedded-Linux/assets/76526170/e06af513-0dd0-431c-95ba-aa26e899e76d)

### Extract 
 -  After tar the file ``` cd linux-6.6.29 ``` to extract the file

### Writing Compiler PATH
 -  CROSS_COMPILE= <PATH> to choose your cross compile path

### Configration Edit
 - To make default conifigrations ```  make ARCH=arm CROSS_COMPILE=../arm-gnu-toolchain/bin/arm-none-linux-gnueabihf- defconfig ``` 
 - Go to menuconfig to change and add you Drivers selection for ur kerel ``` make ARCH=arm CROSS_COMPILE=../arm-gnu-toolchain/bin/arm-none-linux-gnueabihf- -menuconfig ```
   ![Screenshot_2024-04-29_14-35-15](https://github.com/Rabie45/Embedded-Linux/assets/76526170/e4179140-962e-4214-8ed6-2a597e759003)
 - In my case I have problem in AMD GPU So using ``` / ``` in menuconfig
 - Search bar opened search for ```GPU``` And disable the Driver 

### Make compile
 -  ``` make ARCH=arm CROSS_COMPILE=../arm-gnu-toolchain/bin/arm-none-linux-gnueabihf- -j12 ```  The -j option in the make command specifies the number of jobs (parallel processes) that make is allowed to run simultaneously. In your example, -j12 indicates that make should run up to 12 jobs simultaneously, which can speed up the build process by utilizing multiple CPU cores.

 - Then  ``` make ARCH=arm CROSS_COMPILE=../arm-gnu-toolchain/bin/arm-none-linux-gnueabihf- -j12 install ```
install target in the make command typically copies built files from the build directory to their destination directories, making them accessible for system-wide use.

Lets go to busybox....

