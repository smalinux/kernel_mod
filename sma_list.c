#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h> 

#include <linux/proc_fs.h>
#include<linux/sched.h>

#include <linux/pid_namespace.h>

int         p_id = 1;
struct      pid *pid_struct;
struct      task_struct *task, *child;
struct      list_head *list;
char        tty[64];

static void sma_list(void) {
    printk(KERN_WARNING "============================================\n");

























    printk(KERN_WARNING "============================================\n");
}

static int __init proc_init (void) {
    sma_list();
    // -------------------------------------------------------------------
    // create_new_proc_entry();
    return 0;
}

static void __exit proc_cleanup(void) {
    printk(KERN_INFO "Inside cleanup_module\n");
    // remove_proc_entry(proc_name,NULL);
}

MODULE_LICENSE("GPL");   
module_init(proc_init);
module_exit(proc_cleanup);

