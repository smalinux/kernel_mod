u/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static int __init sma_hello(void)
{
	printk(KERN_ERR "Hello world 2.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

static void __exit sma_bye(void)
{
	printk(KERN_INFO "Goodbye world 2.\n");
}
module_init(sma_hello);
module_exit(sma_bye);


MODULE_AUTHOR("Sohaib (smalinux) <sohaibfacebook396@gmail.com>");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("hello Description");
// MODULE_ALIAS();
// MODULE_DEVICE_TABLE();

MODULE_LICENSE("GPL");