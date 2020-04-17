#include <linux/module.h>

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/errno.h>

static void data_cleanup(void)
{
	/* never called */
}

int data_init(void)
{
	/* print information and return an error */
	printk("uname -a\n");
	printk("%s %s %s %s %s %s\n",
		init_uts_ns.name.sysname,
		init_uts_ns.name.nodename,
		init_uts_ns.name.release,
		init_uts_ns.name.version,
		init_uts_ns.name.machine,
		init_uts_ns.name.domainname);
	return -ENODEV;
}

module_init(data_init);
module_exit(data_cleanup);

MODULE_LICENSE("Dual BSD/GPL");