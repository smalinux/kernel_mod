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
# program = my_printk
# program = sma_task_struct_id_2
# program = sma_list
# program = kdatasize
# program = sma_sys
# program = sma_timer
# program = ~sma_jiffies
# program = sma_list_ex2

######## Not Working ########
# program = syscall_mkdir
# program = keylogger_1
# program = smash_MBR

obj-m:= $(program).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc datasize.c -o datasize
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

# Cleaning the code style
style:
	/home/smalinux/Downloads/linux-5.6.3/scripts/Lindent $(program).c 

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean