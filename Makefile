##----------------------- 
# Uncomment one line only:
##----------------------- 
######## Working ########
# program = hello
# program = hello-5
# program = simple_keylogger
# program = task_struct
# program = current
# program = scull
# program = chardev
program = printk

######## Not Working ########
# program = syscall_mkdir
# program = keylogger_1
# program = smash_MBR
# program = task_struct_id

obj-m:= $(program).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
# 	mknod smalinux_node c 10 100 || exit 0

# insert
i:
	insmod $(program).ko

# remove
r:
	rmmod $(program)

# print
p:
	dmesg

# clear dmesg
c:
	dmesg -c

mknod:
	echo "Make node"
# 	$ mknod /dev/devname c majorNum MinorNum

rmnod:
	echo "Remove node"
# 	rm -fr /dev/$(program)

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean