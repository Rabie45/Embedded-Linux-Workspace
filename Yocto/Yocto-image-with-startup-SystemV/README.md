# Yocto-image-with-startup-SystemV
To create script start with project beginning 

## Steps 
 - Go to the layer that you would create the project in
 - ```mkdir hello-startup-sv```
 - ``` cd hello-startup-sv``` then create the recipe ```touch hello-startup-sv.bb```
 - in hello-startup-sv.bb
``` SUMMARY = " Hello python"
LICENSE = "CLOSED"

SRC_URI = "file://startup-sv.sh \
file://hello-startup.py \
"


S = "${WORKDIR}"
RDEPENDS:${PN} = "python3 "
inherit update-rc.d
INITSCRIPT_NAME = "start-python"

INITSCRIPT_PARAMS = "start 99 5 . stop 0 1 6 ."

do_install(){
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/startup-sv.sh ${D}${sysconfdir}/init.d/start-python
    install -d ${D}${bindir}
    install -m 0755 hello-startup.py ${D}${bindir}
}
```
 - Give the bash script to switch about parameter u based to the script
 - And the python  script it self
 - RDEPENDS:${PN} In Yocto, RDEPENDS is used to specify runtime dependencies for a package. To ensure that your package depends on Python 3 at runtime, you can use the RDEPENDS variable in your recipe file
 - ```mkdir files``` to put the scripts in
 - inherit update-rc.d (https://docs.yoctoproject.org/dev-manual/new-recipe.html   5.14)
![image](https://github.com/Rabie45/Yocto-image-with-startup/assets/76526170/1a98d5e4-8b98-4a11-83ac-093abef11085)
 - now run the recipe
 - run the image & run qemu
 - ![image](https://github.com/Rabie45/Yocto-image-with-startup/assets/76526170/4b37f011-ce6d-4796-ae37-cc0ad9482ec5)


