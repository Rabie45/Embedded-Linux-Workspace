# yocto-add-install-features
## To install features
  - go to ```/home/rabi3/poky/poky/build/conf/local.conf``` add ```IMAGE_INSTALL:append = " python3"```
  - To add python to ur image
## To add feature 
  - go to  ```/home/rabi3/poky/poky/meta/recipes-core/images/core-image-minimal.bb``` add ``` IMAGE_FEATURES += "ssh-server-dropbear ``` To add ssh # - weston              - Weston Wayland compositor
#Features to be add
#- x11                 - X server
#- x11-base            - X server with minimal environment
#- x11-sato            - OpenedHand Sato environment
#- tools-debug         - debugging tools
#- eclipse-debug       - Eclipse remote debugging support
#- tools-profile       - profiling tools
#- tools-testapps      - tools usable to make some device tests
#tools-sdk           - SDK (C/C++ compiler, autotools, etc.)
#- nfs-server          - NFS server
#- nfs-client          - NFS client
#- ssh-server-dropbear - SSH server (dropbear)
#- ssh-server-openssh  - SSH server (openssh)
#- hwcodecs            - Install hardware acceleration codecs
#- package-management  - installs package management tools and preserves the package manager database
#- debug-tweaks        - makes an image suitable for development, e.g. allowing passwordless root logins
#- empty-root-password
#- allow-empty-password
#- allow-root-login
#- post-install-logging
#- dev-pkgs            - development packages (headers, etc.) for all installed packages in the rootfs
#- dbg-pkgs            - debug symbol packages for all installed packages in the rootfs
#- lic-pkgs            - license packages for all installed pacakges in the rootfs, requires
#LICENSE_CREATE_PACKAGE="1" to be set when building packages too
#- doc-pkgs            - documentation packages for all installed packages in the rootfs
#- bash-completion-pkgs - bash-completion packages for recipes using bash-completion bbclass
#- ptest-pkgs          - ptest packages for all ptest-enabled recipes
#- read-only-rootfs    - tweaks an image to support read-only rootfs
#- stateless-rootfs    - systemctl-native not run, image populated by systemd at runtime
#- splash              - bootup splash screen

