Must to read this 				https://github.com/cirosantilli/linux-kernel-module-cheat
Very cute series 				https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-part-1-introduction/



List of all kernel DS:			https://docs.huihoo.com/doxygen/linux/kernel/3.7/annotated.html
Linux Kernel APIs				https://www.kernel.org/doc/htmldocs/kernel-api/index.html
Linked List 					https://web.archive.org/web/20190215080058/http://isis.poly.edu/kulesh/stuff/src/klist/
Random tutorials				https://tuxthink.blogspot.com/search?q=kernel
Kernel dev BooK					http://books.gigatux.nl/mirror/kerneldevelopment/0672327201/toc.html
TLDP Kernel Book				https://www.tldp.org/LDP/tlk/tlk-toc.html
TLDP kernel internal book 		http://www.tldp.org/LDP/lki/lki.html
0xAX book 						https://github.com/0xAX/linux-insides/blob/master/SUMMARY.md
best view for any DS 			https://docs.huihoo.com/doxygen/linux/kernel/3.7/structtask__struct.html
Kernel books 					http://kernelbook.sourceforge.net/
newbies							https://www.spinics.net/lists/newbies/msg11186.html
PLKA 							https://www.amazon.com/dp/0470343435
UtLK							Understanding the Linux Kernel
LDDD							9781785280009
Nice blogspot 					https://tuxthink.blogspot.com/2012/05/working-of-macros-majorminor-and-mkdev.html
read this nice example 			https://github.com/lvming/sample-modules/blob/master/sample-misc.c
Linux Kernel API 				https://www.fsl.cs.sunysb.edu/kernel-api/index.html
What? 							https://yarchive.net/comp/linux/put_user.html
Cutest blog 					https://olegkutkov.me/2018/03/14/simple-linux-character-device-driver/
https://www.linuxtopia.org/online_books/Linux_Kernel_Module_Programming_Guide/index.html
https://sysplay.github.io/books/LinuxDrivers/book/Content/Part09.html
https://events19.linuxfoundation.org/wp-content/uploads/2017/12/Introduction-to-Linux-Kernel-Driver-Programming-Michael-Opdenacker-Bootlin-.pdf
https://stackoverflow.com/q/21173988/5688267
https://elinux.org/
https://kernel.readthedocs.io/en/latest/
https://kernelnewbies.org/
https://stackoverflow.com/questions/9305992/if-threads-share-the-same-pid-how-can-they-be-identified
https://stackoverflow.com/questions/33594124/why-is-the-process-state-in-task-struct-stored-as-type-long
https://stackoverflow.com/q/15610570/5688267
http://junyelee.blogspot.com/2018/11/platform-devices-and-drivers.html






task_struct:
	https://www.spinics.net/lists/newbies/msg11186.html






List:
	http://www.davidespataro.it/kernel-linux-list-efficient-generic-linked-list/
	https://www.quora.com/Why-are-all-the-linked-lists-circular-in-the-Linux-Kernel
	https://www3.cs.stonybrook.edu/~dongyoon/cse506-f19/lecture/lec06-kds1.pdf
	https://github.com/0xAX/linux-insides/blob/master/SUMMARY.md
	https://www.kernel.org/doc/html/v4.14/core-api/kernel-api.html
	https://www.cs.uic.edu/~hnagaraj/articles/linked-list/
	https://davejingtian.org/2013/04/03/linux-kernel-linked-list/
	https://medium.com/@414apache/kernel-data-structures-linkedlist-b13e4f8de4bf
	https://github.com/0xAX/linux-insides/blob/master/DataStructures/linux-datastructures-1.md
	http://www.makelinux.net/ldd3/chp-11-sect-5.shtml

	https://notes.eddyerburgh.me/operating-systems/linux/kernel-data-structures

	Google: linux kernel data structures

	http://krishnamohanlinux.blogspot.com/2014/06/linkedlist-in-kernel-example.html
	https://kernelnewbies.org/FAQ/LinkedLists
	https://www.spinics.net/lists/newbies/msg11186.html



Read it later:
	https://stackoverflow.com/questions/10696863/any-example-of-copy-from-user-kernel-and-userspace/22890993
	http://rcjangir.blogspot.com/2012/08/example-of-char-device-driver.html
	https://olegkutkov.me/2018/03/14/simple-linux-character-device-driver/
	https://www.cs.bham.ac.uk/~exr/lectures/opsys/13_14/examples/deviceDriver/charDeviceDriver.c


procfs:
	https://lkw.readthedocs.io/en/latest/doc/05_proc_interface.html
	https://devarea.com/linux-kernel-development-creating-a-proc-file-and-interfacing-with-user-space/#.XptT6vIzbeQ
	https://www.linuxtopia.org/online_books/Linux_Kernel_Module_Programming_Guide/x814.html
	https://linux.die.net/lkmpg/x769.html
	https://gist.github.com/BrotherJing/c9c5ffdc9954d998d1336711fa3a6480
	http://www.cs.fsu.edu/~cop4610t/lectures/project2/procfs_module/proc_module.pdf
	https://lore.kernel.org/netdev/20191225172546.GB13378@avx2/
	https://github.com/torvalds/linux/commit/d56c0d45f0e27f814e87a1676b6bdccccbc252e9
	https://idea.popcount.org/2012-12-11-linux-process-states/
	https://www.tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html
	http://tldp.org/LDP/lkmpg/2.6/html/index.html
	https://www.youtube.com/watch?v=2Txu6umbsKE&t=943s
	https://lore.kernel.org/linux-fsdevel/20191225172228.GA13378@avx2/


sysfs:
	https://embetronicx.com/tutorials/linux/device-drivers/sysfs-in-linux-kernel/
	https://www.cs.swarthmore.edu/~newhall/sysfstutorial.pdf
	http://linuxkernel51.blogspot.com/2015/08/sample-code-to-create-sysfs-interface.html


Kernel Data Structures:
	Workqueue
	List
	Waitqueue
	Tasklet
	Timer
	Completion
	mutex
	spinlock



========================================================================

sbull.c 			-- disk driver
Simple 				-- REALLY simple memory mapping demonstration.
snull.c 			-- the Simple Network Utility
skull.c 			-- sample typeless module.
tiny_serial.c 		-- Tiny Serial driver
tiny_tty.c 			-- Tiny TTY driver
usb-skeleton.c 		-- USB Skeleton driver
scull 				-- the bare scull char module
scullc				-- the bare scullc char module
sculld 				-- the bare sculld char module
scullp 				-- the bare scullp char module
scullv 				-- the bare scullv char module
short.c 			-- Simple Hardware Operations and Raw Tests
shortprint.c 		-- A version of the "short" driver which drives a parallel printer directly.



fs.h 									struct register_chrdev_region
fs.h 									struct file_operations
fs.h 									struct inode
fs.h 									struct file

thread_info.h
list.h
proc_fs.h
uaccess.h
slab.h
string.h




platform_device.h
mod_devicetable.h


========================================================================

0.  platform devices == on-chip devices (SoC) == USB, I2S, I2C, UART, SPI, PCI, SATA, and so on.
0.  pseudo platform bus == platform bus

1. Register a platform driver (with a unique name) that will manage your devices
2. Register your platform device with the same name as the driver, and their
resources, in order to let the kernel know that your device is there


$ lsusb
$ lsusb -v



========================================================================
	LDDD
========================================================================

LDDD Source Code:
	https://github.com/PacktPublishing/Linux-Device-Drivers-Development


Color imgs of this book:
	https://static.packt-cdn.com/downloads/LinuxDeviceDriversDevelopment_ColorImages.pdf

linux/Documentation/:
linux/include/:
	// This should be your favorite directory.


linux/scripts/: 
	// This contains scripts and tools used during kernel development.
	// There are other useful tools here



# initramfs ?


========================================================================
	End LDDD
========================================================================

= kernelnewbies
	= Kernelnewbies mailing list Archives : http://lists.kernelnewbies.org/pipermail/kernelnewbies/


Rasbiry pi:
	Book: Mastering embedded linux programming-Cris simmeds
	Book: Embedded linux development using yotco progict Cookbook
	Book: Mastering linux kernel development 
--------------------------------------------



























































































































