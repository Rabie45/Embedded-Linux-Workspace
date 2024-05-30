# Qemu 
![image](https://github.com/Rabie45/Embedded-Linux/assets/76526170/e0b7e9a2-9ff7-4af2-97b4-e89942781041)

``` https://www.qemu.org/download/#linux ```
## Steps
### Download
  - apt-get install qemu-system 
### Create root file system
In Linux, a root filesystem (rootfs) is the initial filesystem that is mounted when the system boots up. It contains essential files and directories necessary for the system to function properly. The root filesystem typically includes directories such as /bin, /sbin, /lib, /usr, /etc, and /dev, among others.

Here's a brief overview of what each of these directories contains:

/bin: Contains essential binary executable files that are required for system operation, such as basic system commands like ls, cp, mv, and mkdir.
/sbin: Similar to /bin, but contains binary executable files for system administration tasks that require superuser (root) privileges, such as ifconfig, mount, and shutdown.
/lib: Contains shared library files (.so files) that are needed by the executables in /bin and /sbin.
/usr: Contains secondary hierarchy for read-only user data; usually includes directories like /usr/bin and /usr/sbin for additional executables, /usr/lib for additional libraries, and /usr/share for architecture-independent data.
/etc: Contains configuration files for the system and installed applications.
/dev: Contains device files that represent physical and virtual devices attached to the system.
The root filesystem is usually mounted from an initial RAM disk (initramfs) during the boot process, which allows the kernel to access necessary drivers and utilities to mount the actual root filesystem, which may reside on a separate storage device such as a hard drive or an SSD.

  - ```mkdir -p rootfs/{bin,sbin,etc,proc,sys,usr/{bin,sbin}}```
  - Go to  ```ls rootfs```
  - Copy the data from busybox install which we made to rootfs ```cp -av busybox-1.36.1/_install/* rootfs/ ```
  - The command ln -sf bin/busybox init creates a symbolic link named init that points to the busybox executable file located in the bin directory. ```ln -sf bin/busybox  init  ```
  - mknod: This is the command used to create device special files.
  - ``` mkdir dev```
  - ```cd dev```
  - ```sudo mknod -m 660 mem c 1 1```
  - ```sudo mknod -m 660 tty4 c 4 4 ```
  - ```sudo mknod -m 660 tty3 c 4 3 ```
  - ```sudo mknod -m 660 tty2 c 4 2 ```

### Compress rootfs
  - ```find . -print0 | cpio --null -ov --format=newc | gzip -9 > ../rootfs.cpio```   
The command you provided is used to create a compressed archive of the current directory (and its subdirectories) using the find and cpio commands, and then compressing it with gzip. Here's a breakdown of what each part of the command does:

find . -print0: This command recursively finds all files and directories in the current directory (.) and prints their names to standard output, separated by null characters (-print0). The null character is used as a delimiter to handle filenames with spaces or special characters.
|: This is a pipe symbol, used to redirect the output of one command (in this case, find) to the input of another command (in this case, cpio).
cpio --null -ov --format=newc: This command reads the list of files and directories from standard input, delimited by null characters (--null), and creates a new cpio archive (-ov) using the newc format (--format=newc). The newc format is a variant of the cpio format optimized for use with the Linux kernel.
|: Another pipe symbol to redirect the output of cpio to the input of the next command.
gzip -9: This command compresses the input data using the gzip compression algorithm, with the highest compression level (-9). The compressed output is written to standard output.
> ../rootfs.cpio: This part of the command redirects the compressed output to a file named rootfs.cpio in the parent directory (..). The > operator is used for output redirection.

### Finally Run qemu
```qemu-system-arm -M virt -m 256M -kernel /home/rabi3/Desktop linux-6.6.29/arch/arm/boot/zImage -initrd /home/rabi3/Desktop rootfs.cpio -append "root=/dev/mem" -nographic ```
Here's a breakdown of each part of the command:

qemu-system-arm: This is the QEMU emulator for ARM architecture.
-M virt: This option specifies the machine type to emulate. In this case, it's emulating a virtual machine with a generic ARM virtual board.
-m 256M: This sets the amount of RAM available to the virtual machine to 256 megabytes.
-kernel /home/rabi3/Desktop/linux-6.6.29/arch/arm/boot/zImage: This specifies the path to the kernel image file (zImage) that QEMU will boot.
-initrd /home/rabi3/Desktop/rootfs.cpio: This option specifies the initial ramdisk (initrd) image to use. It loads the root filesystem (rootfs.cpio) into memory.
-append "root=/dev/mem": This appends the given string to the kernel command line. In this case, it specifies the root filesystem device as /dev/mem.
-nographic: This option disables graphical output and redirects the virtual machine's console to the terminal where QEMU was launched.
