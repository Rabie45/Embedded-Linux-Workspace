# Custom-yocto-image
Creating a customized Yocto image involves several steps, including setting up the build environment, configuring the build to include specific packages and features, and building the image.
in this image we will add splash bootup strace and ssh

## First create layer
 - ```bitbake-layers create-layer ../meta-custom``` To create the layer
   ![image](https://github.com/Rabie45/Custom-yocto-image/assets/76526170/aca483a0-f80a-4ab9-876f-766a39f9f433)

 - ```bitbake-layers add-layer ../meta-custom```   to add a new layer in Yocto simplifies the process of managing layers in your build environment.
   
   ![image](https://github.com/Rabie45/Custom-yocto-image/assets/76526170/53866b2e-e16d-4368-8932-9cfda1c794a1)

 - ```mkdir -p meta-diploma/recipes-core/``` to add some core files 
 - ```mkdir -p meta-diploma/recipes-core/images/``` to add the customized image
 - ```touch customize-minimal.bb```
 -
``` include recipes-core/images/core-image-minimal.bb
IMAGE_FEATURES += " ssh-server-dropbear "
IMAGE_INSTALL += " strace"
```
- include core-image-minimal configration
- add feature ssh
- add strace
- ```mkdir -p meta-diploma/recipes-core/base-files/```  to append your hostname to the image
- ```touch meta-diploma/recipes-core/base-files/base-files_%.bbappend ``` file name must have the same format
- open file add ```hostname = "YOUR HOST NAME" ```
- go to build file ``` cd build/```
- run ```bitbake customize-minimal```
- ![image](https://github.com/Rabie45/Custom-yocto-image/assets/76526170/2cf3dd8a-dca3-40e4-b9a0-30c16f05b344)
- run ```runqemu qemux86-64```
- 

https://github.com/Rabie45/Custom-yocto-image/assets/76526170/afdbe420-f53a-4512-8572-0784487f7040


- You can see psplash added and ssh 



