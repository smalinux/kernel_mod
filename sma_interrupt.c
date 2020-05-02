/*  
 *  sma_interrupt.c - interrupt handler
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static int __init sma_hello(void)
{
	pr_info("Hello world.\n");
	
	return 0;
}

static void __exit sma_bye(void)
{
	pr_info("Goodbye world.\n");
}
module_init(sma_hello);
module_exit(sma_bye);

/** MODULE_
*/
MODULE_AUTHOR("Sohaib (smalinux) <sohaibfacebook396@gmail.com>");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("hello Description");
// MODULE_ALIAS();
// MODULE_DEVICE_TABLE();
MODULE_LICENSE("GPL");