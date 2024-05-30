# How-to-create-kernel-module
Basic example of a Linux kernel module. It includes both initialization and cleanup functions. Here is the cleaned-up and commented version of the code for clarity

## First you have to download the libs
```  sudo apt install linux-headers-$(uname -r)   ``` 
to download the header and ``` uname -r``` to download suitable for your device 

## Second add the path in vscode 
``` ctrl + shift + p ``` to open json configration
``` {
    "configurations": [
        {
            
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include",
                "/usr/local/include",
                "/usr/src/linux-headers-5.15.0-106-generic/include/",
                "/usr/src/linux-headers-5.15.0-106-generic/arch/arm/include/"
            ],
            "defines": [
    
                "__GNUC__",
                "__KERNEL__",
            ],
            "compilerPath": "/usr/bin/clang-11",
            "cStandard": "c17",
            "cppStandard": "c++14",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```
## Third create the c script 
 - include the headers
```#include <linux/module.h> // Needed for all kernel modules
#include <linux/init.h> // Needed for KERN_INFO
#include <linux/kernel.h> // Needed for the macros
 ```
 - Create moudle license, Autoir name and desription
```
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rabie");
MODULE_DESCRIPTION("HELLo world device deriver");
```
GPL : genral punlic license 
Proprietary: Indicates that the module is proprietary and not open source.
 - When module init print hello world
```
static int __init hellodriver_init(void){
    printk(KERN_INFO,"hello world\n");
    return 0;
}
```
- When module exit print good bye
```
static void __exit hellodriver_exit(void){
    printk(KERN_INFO,"Good bye,");
}
```

- Call the modules
 ```
module_init(hellodriver_init);
module_exit(hellodriver_exit);
```

## Add to kernel
 - ``` make ```
 - ```  sudo insmod hello.ko       ```
 - ``` sudo dmesg | tail ```
 - ![image](https://github.com/Rabie45/How-to-create-kernel-module/assets/76526170/123b767c-a298-4aec-8760-d82fdf4595b2)


