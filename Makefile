##----------------------- 
# Uncomment one line only:
##----------------------- 
# program = hello
# program = hello-5  # insmod hello-5.ko mystring="bebop" mybyte=255 myintArray=-1
program = hello


obj-m:= $(program).o



all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules


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