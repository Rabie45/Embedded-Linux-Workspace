# Croostool -ng 
crosstool-NG is a versatile tool for building cross-compilation toolchains. It allows developers to generate toolchains that can compile code for different architectures and platforms, making it especially useful for embedded systems development.

## Steps
### Download
   ```  sudo apt-get install build-essential git autoconf bison flex texinfo help2man gawk libtool-bin libncurses5-dev ```
   
### Clone the repo
``` git clone  https://github.com/crosstool-ng/crosstool-ng.git  ```

### Open the repo
``` cd crosstool-ng    ```
``` git checkout crosstool-ng-1.26.0   ``` Use this stable version
### Bootstaping
```./bootstrap ```  In the context of Crosstool-NG, running ./bootstrap initializes the Crosstool-NG build system and prepares it for configuration and compilation.

### Confiraion 
``` ./configure --enable-local  ```        
The command ./configure --enable-local is used to configure Crosstool-NG with the local backend enabled. This option allows you to build toolchains using locally available toolchain components 

### Set the compiler for Arm Arch
``` ./ct-ng arm-unknown-linux-gnueabi ``` 

### Menuconfig
   - ``` ./ct-ng menuconfig```  To change ur target or add librar ... etc
![Screenshot_2024-04-29_14-45-52](https://github.com/Rabie45/Embedded-Linux/assets/76526170/143cd952-df42-4123-af3d-a8d4e52c57c8)

### Build
```./ct-ng build ```

you will find Your compiler in this path
/home/<Name>/x-tools/
