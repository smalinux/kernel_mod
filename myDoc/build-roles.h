------------------------
Make a new Makefiles ...
------------------------



= Quit QEMU from text mode
----------------------------
	> Ctrl-A X
	> quit command on the QEMU monitor (Ctrl-A C then quit)
	> pkill qemu

= Fast Build
----------------------------
	./build-linux
	./run

= kernel module hack 		https://github.com/cirosantilli/linux-kernel-module-cheat#your-first-kernel-module-hack
----------------------------
	./build-modules
	./build-buildroot
	./run --dry-run --kvm --eval-after 'insmod hello.ko'

= 

