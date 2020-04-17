/*
*
* sma_ is a prefix
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>

struct sma_names {
    struct list_head list;
    char name[20];
};


int c = 0;

static void sma_list(void) {
    printk(KERN_WARNING "============================================\n");

    struct list_head sma_names;

    INIT_LIST_HEAD(&sma_names);

    struct list_head h1;

    list_add(&h1, &sma_names);

    struct list_head *listptr;
    // struct sma_names *entry;

    list_for_each(listptr, &sma_names) {
        printk("Item %d", ++c);
    }






















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

