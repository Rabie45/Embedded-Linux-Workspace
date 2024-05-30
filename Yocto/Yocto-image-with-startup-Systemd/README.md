# Yocto-image-with-startup-Systemd
To create script start with project beginning systemd

## Steps 
 - Go to the layer that you would create the project in
 - ```mkdir hello-startup-sv```
 - ``` cd hello-startup-sv``` then create the recipe ```touch hello-startup-sv.bb```
 - in hello-startup-sv.bb
``` SUMMARY = " Hello python"
LICENSE = "CLOSED"

SRC_URI = "file://hello-startup-sysd.py \
file://sd-start.service\
"


S = "${WORKDIR}"
RDEPENDS:${PN} = "python3 "
inherit systemd


INITSCRIPT_PARAMS = "start 99 5 . stop 0 1 6 ."

do_install(){
    install -d ${D}${systemd_system_unitdir}
    install -m 0744 ${WORKDIR}/sd-start.service ${D}${systemd_system_unitdir}
    install -d ${D}${bindir}
    install -m 0744 hello-startup-sysd.py ${D}${bindir}
}
SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_AUTO_ENABLE ??= "enable"
SYSTEMD_SERVICE:${PN} = "sd-start.service"
```
 - Create the service
```
[Unit]
Description="Hello world sysd"

[Service]
ExecStart=python3 /usr/bin/hello-startup-sysd.py


[Install]
WantedBy=multi-user.target
```
![image](https://github.com/Rabie45/Yocto-image-with-startup-Systemd/assets/76526170/c02b2d69-796f-4d07-b65f-6c204996ac21)

![29 05 2024_00 13 06_REC](https://github.com/Rabie45/Yocto-image-with-startup-Systemd/assets/76526170/7e1da0bb-0237-4c6f-aefd-0634cd757d59)
