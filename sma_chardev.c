/*  
 *  sma_chardev.c - Full example of character device driver.
 *	step 1: Hello, world!
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static int __init sma_init(void)
{
	printk(KERN_ERR "Hello world.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

static void __exit sma_exit(void)
{
	printk(KERN_INFO "Goodbye world.\n");
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