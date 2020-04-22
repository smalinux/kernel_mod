
# Set module name from the list:
program = sma_usb


# 'The list'
#----------
obj-m += sma_usb.o
# obj-m += sma_chardev.o
# obj-m += sma_skeleton.o
# obj-m += hello.o
# obj-m += hello-5.o
# obj-m += simple_keylogger.o
# obj-m += task_struct.o
# obj-m += current.o
# obj-m += scull.o
# obj-m += chardev.o
# obj-m += my_printk.o
# obj-m += sma_task_struct_id_2.o
# obj-m += sma_list.o
# obj-m += kdatasize.o
# obj-m += sma_sys.o
# obj-m += sma_timer.o
# obj-m := sma_jiffies.o
# obj-m := sma_list_ex2.o

######## Not Working ########
# program = syscall_mkdir
# program = keylogger_1
# program = smash_MBR



all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc datasize.c -o datasize
# 	mknod smalinux_node c 10 100 || exit 0

# insert
i:
# 	depmod -ae 			https://stackoverflow.com/a/34800857/5688267
	cp $(program).ko /lib/modules/$(shell uname -r)/
	sudo modprobe $(program)

# remove
r:
	modprobe -r $(program)
	rm /lib/modules/$(shell uname -r)/$(program).ko

# print
p:
	dmesg

l:
	lsmod | grep $(program)

# clear dmesg
c:
	dmesg -c

mknod:
	echo "Make node"
# 	$ mknod /dev/devname c majorNum MinorNum

rmnod:
	echo "Remove node"
# 	rm -fr /dev/$(program)

# Cleaning the code style
style:
	/home/smalinux/Downloads/linux-5.6.3/scripts/Lindent $(program).c

info:
	modinfo $(program).ko 			#userspace program prints .modinfo section

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean