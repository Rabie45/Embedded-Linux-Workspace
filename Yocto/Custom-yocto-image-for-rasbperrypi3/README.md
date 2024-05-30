# Custom-yocto-image-for-rasbperrypi3
Creating a custom Yocto image for Raspberry Pi 3 involves several steps, from setting up the Yocto build environment to customizing the image by adding layers and recipes. Below is a detailed guide to help you through the process.

## Steps to create yocto image for rassbperrypi3
 - go to poky in your device and clone the layer of rassbperrypi3
 - ``` git clone git://git.yoctoproject.org/meta-raspberrypi ```
 - ``` source oe-init-build-env```
 - now you are in build directory
 - Add the meta-raspberrypi layer to your project
 - ``` bitbake-layers add-layer ../meta-raspberrypi/```
 - go to ```/poky/build/conf```
 - open it and change the machine to ```MACHINE ??= "raspberrypi3"``` insted of MACHINE ??= "raspberrypi3"
 - then ```bitbake linux-raspberrypi ``` it should work succefuly but it give me multbile errors multible time
```ERROR: linux-raspberrypi-1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0 do_fetch: Fetcher failure: Fetch command export PSEUDO_DISABLED=1; export DBUS_SESSION_BUS_ADDRESS="unix:path=/run/user/1000/bus"; export SSH_AUTH_SOCK="/run/user/1000/keyring/ssh"; export PATH="/home/rabi3/poky/poky/build/tmp/sysroots-uninative/x86_64-linux/usr/bin:/home/rabi3/poky/poky/scripts:/home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/recipe-sysroot-native/usr/bin/arm-poky-linux-gnueabi:/home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/recipe-sysroot/usr/bin/crossscripts:/home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/recipe-sysroot-native/usr/sbin:/home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/recipe-sysroot-native/usr/bin:/home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/recipe-sysroot-native/sbin:/home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/recipe-sysroot-native/bin:/home/rabi3/poky/poky/bitbake/bin:/home/rabi3/poky/poky/build/tmp/hosttools"; export HOME="/home/rabi3"; LANG=C git -c core.fsyncobjectfiles=0 -c gc.autoDetach=false -c core.pager=cat clone --bare --mirror https://github.com/raspberrypi/linux.git /home/rabi3/poky/poky/build/downloads/git2/github.com.raspberrypi.linux.git --progress failed with exit code 128, no output
ERROR: linux-raspberrypi-1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0 do_fetch: Bitbake Fetcher Error: FetchError('Unable to fetch URL from any source.', 'git://github.com/raspberrypi/linux.git;name=machine;branch=rpi-5.15.y;protocol=https')
ERROR: Logfile of failure stored in: /home/rabi3/poky/poky/build/tmp/work/raspberrypi3-poky-linux-gnueabi/linux-raspberrypi/1_5.15.92+gitAUTOINC+509f4b9d68_14b35093ca-r0/temp/log.do_fetch.504466
ERROR: Task (/home/rabi3/poky/poky/meta-raspberrypi/recipes-kernel/linux/linux-raspberrypi_5.15.bb:do_fetch) failed with exit code '1'
 ```

 - this error say that the bitbake cant fetch the github repo due to some issues but in your consediration it might be due to internet connection issue but in my case the problem after search due to this file /poky/meta-raspberrypi/recipes-kernel/linux/linux-raspberrypi_5.15.bb as it said in the last error so i tried to change linux version to ```LINUX_VERSION ?= "5.15.28"``` and src ```#SRCREV_machine = "ab46d8de9f2406eb8e4ee0bd0b1b093cef59a1de"``` but it surprized my with new issue
  ![image](https://github.com/Rabie45/Custom-yocto-image-for-rasbperrypi3/assets/76526170/53863b47-f712-41c8-84f8-afdaa2c44fa3)
 - then i used this version and t finally worked with some warnings XD  ```LINUX_VERSION ?= "5.10.110"``` and  ```SRCREV_machine = "89c0af71c9cf157a865afb526e9ebc21aadd531b"```
  ![image](https://github.com/Rabie45/Custom-yocto-image-for-rasbperrypi3/assets/76526170/bf4cf3e2-4c6a-4ddf-a067-64f2f556c94f)
   


 
                                                                                                                                                                           
