/*  
 *	Linux virtual filesystems
 *	Ref: https://lwn.net/Articles/57369/
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static int __init sma_hello(void)
{
	printk(KERN_ERR "Hello world\n");


	return 0;
}

static void __exit sma_bye(void)
{
	printk(KERN_INFO "Goodbye world\n");
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