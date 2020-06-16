/*  
 *  sma_skeleton.c - The simplest kernel module.
 */
#include <linux/module.h>	/* __init & __exit */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static char *name = "Sohaib";

static void say_my_name(char *name)
{
	pr_info("My name is: %s\n", name);
}

static int __init sma_hello(void)
{
	say_my_name(name);
	pr_err("Hello world.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

static void __exit sma_bye(void)
{
	printk(KERN_INFO "Goodbye world.\n");
}

/*
*	MODULE_*
*/
module_init(sma_hello);
module_exit(sma_bye);

module_param(name, charp, 0);
MODULE_PARM_DESC(name, "Just prints your cute name!");

MODULE_VERSION("1.0");
MODULE_INFO(love,"Aya Mohammed <+2010xxxxxxx>"); 	// Random Name :P
MODULE_DESCRIPTION("Basic Module");
MODULE_AUTHOR("Sohaib <xunilams@gmail.com>");
MODULE_LICENSE("GPL");