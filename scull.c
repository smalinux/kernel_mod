/*
SCULL: Simple Character Utility for Loading Localities
*/
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/kdev_t.h>
#include <linux/fs.h>

int scull_major = 10;
int scull_minor = 100;
int scull_nr_devs = 5;

static int register_major_minor(void) {
	int result;
	dev_t dev = 0;

	if (scull_major) {
		dev = MKDEV(scull_major, scull_minor);
		result = register_chrdev_region(dev, scull_nr_devs, "scull");
	} else {
		result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs, "scull");
		scull_major = MAJOR(dev);
	}
	if (result < 0)
	{
		printk(KERN_WARNING "scull: can't get major %d.\n", scull_major);
		return result;
	}
	printk(KERN_WARNING "register_major_minor: Done!.\n");
	return 0;
}

static int __init sma_hello(void)
{
	register_major_minor();
	printk(KERN_ERR "Hello world 2.\n");
	return 0;
}

static void __exit sma_bye(void)
{
	// unregister_major_minor();
	printk(KERN_INFO "Goodbye world 2.\n");
}
module_init(sma_hello);
module_exit(sma_bye);





/** MODULE_
*/
MODULE_AUTHOR("Sohaib (smalinux) <xunilams@gmail.com>");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("hello Description");
// MODULE_ALIAS();
// MODULE_DEVICE_TABLE();
MODULE_LICENSE("GPL");