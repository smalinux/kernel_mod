/*  
 *  printk.c - xxx.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/printk.h>	/* Needed for KERN_INFO */

static int __init sma_hello(void)
{
	printk(KERN_EMERG "Hello world 2.\n");
	printk(KERN_ALERT "Hello world 2.\n");
	printk(KERN_CRIT "Hello world 2.\n");
	printk(KERN_ERR "Hello world 2.\n");
	printk(KERN_WARNING "Hello world 2.\n");
	printk(KERN_NOTICE "Hello world 2.\n");
	printk(KERN_INFO "Hello world 2.\n");
	printk(KERN_DEBUG "Hello world 2.\n");

	return 0;
}

static void __exit sma_bye(void)
{
	printk(KERN_INFO "Goodbye world 2.\n");
}

module_init(sma_hello);
module_exit(sma_bye);

MODULE_LICENSE("GPL");