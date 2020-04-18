/*  
 *  sma_chardev.c - Full example of character device driver.
 *	step 1: Hello, world!
 * 	step 2: Allocating and registering a character device.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/fs.h>	/* alloc_chrdev_region & unregister_chrdev_region */
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>

#define SMA_DEVICE_NAME "sma_chardev"
#define SMA_CLASS_NAME "sma_class"

static unsigned int major; /* major number for device */
static struct class *sma_class;
static struct cdev sma_cdev;
static dev_t devt = 0;
// static dev_t dev_num = 0;

int dummy_open(struct inode * inode, struct file * filp)
{
    pr_info("Someone tried to open me\n");
    return 0;
}


struct file_operations sma_fops = {
    open:       dummy_open,
    // release:    dummy_release,
    // read:       dummy_read,
    // write:      dummy_write,
};

/* Allocating and registering My character
device */
static int register_ma_mi(void) {
	struct device *sma_device;
	int error;

	/* Alloc char device */
	error = alloc_chrdev_region(&devt, 0, 1, SMA_DEVICE_NAME);
	if (error < 0)
	{
		pr_err("Failed to allocate chrdev region\n");
		return error;
	}

	major = MAJOR(devt);	/* get major num */
    pr_info("sma_chardev major number = %d\n",major);

	/* Let's create our class, visible in /sys/class  */
	sma_class = class_create(THIS_MODULE, SMA_CLASS_NAME);

	if (IS_ERR(sma_class)) {
		pr_err("Error creating sma_class.\n");
		unregister_chrdev_region(MKDEV(major, 0), 1);
		return PTR_ERR(sma_class);
    }

	/* Tie file_operations to cdev */
	cdev_init(&sma_cdev, &sma_fops);
	sma_cdev.owner = THIS_MODULE;

	/* Make the device live for the users to access */
	cdev_add(&sma_cdev, devt, 1);

	/* Create a device node each device /dev/eep-mem0, /dev/eep-mem1,
	*  with our class used here.
	*  device can also be viewed under /sys/class/eep-class.
	*/
	sma_device = device_create(sma_class,
		NULL,			/* no parent device */
		devt,
		NULL,			/* no additonal data */
		SMA_DEVICE_NAME);	/* device name */

	pr_info("sma_chardev module is loaded.\n");
	return error;
}

static int __init sma_init(void)
{
	int callback;
	callback = register_ma_mi();	/* Rigister Major & Minor numbers */

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	/* Failed to allocate chrdev region */
	return callback;
}

static void __exit sma_exit(void)
{
	unregister_chrdev_region(MKDEV(major, 0), 1);
    device_destroy(sma_class, MKDEV(major, 0));
    cdev_del(&sma_cdev);
    class_destroy(sma_class);

    pr_info("sma_chardev module Unloaded\n");
}

module_init(sma_init);
module_exit(sma_exit);

/** MODULE_
*/
MODULE_AUTHOR("Sohaib (smalinux) <sohaibfacebook396@gmail.com>");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("Full example of character device driver");
// MODULE_ALIAS();
// MODULE_DEVICE_TABLE();
MODULE_LICENSE("GPL");