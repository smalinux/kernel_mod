Wow - Collection of kernel example
	https://code.woboq.org/linux/linux/samples/


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


#include <linux/>
thread_info.h
list.h
proc_fs.h
uaccess.h
slab.h
string.h
linux/moduleparam.h



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


/* linux/moduleparam.h
*/
struct Module_parameters_macros {
	module_param()
	module_param_array()
	module_param_cb()
}


/* S_I just a prefix 
	R = read, W = Write, X = Execute
	USR = user, GRP = Group
*/
struct permissions{
	S_IWUSR 		/* Write user */
	S_IRUSR 		/* Read user */
	S_IXUSR			/* Exec user */
	etc ..
}






Google:
	seccomp
	bpf filters
	ebpf linux kernel
	read about System-V






































































































