#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include<linux/sysfs.h> 
#include<linux/kobject.h> 
#include <linux/interrupt.h>
#include <asm/io.h>
#include <linux/workqueue.h>            // Required for workqueues

/* Function Declarations */
// static void sma_list(void);

/* My Structs */
static struct eyes_t {
    char *color;
    int numbers;
    struct list_head list;
};

LIST_HEAD(eyes);

/* init function */
static int __init list_init(void) {

    /* Some instances: eyes_t */
    struct eyes_t *red_eye    = kmalloc(sizeof(struct eyes_t), GFP_KERNEL);
    struct eyes_t *blue_eye   = kmalloc(sizeof(struct eyes_t), GFP_KERNEL);
    struct eyes_t *black_eye  = kmalloc(sizeof(struct eyes_t), GFP_KERNEL);
    struct eyes_t *green_eye  = kmalloc(sizeof(struct eyes_t), GFP_KERNEL);


    red_eye->color = "Red";
    blue_eye->color = "Blue";
    black_eye->color = "Black";
    green_eye->color = "Green";

    red_eye->numbers = 1;
    blue_eye->numbers = 2;
    black_eye->numbers = 3;
    green_eye->numbers = 4;

    /* Initialize each node's list entry */
    INIT_LIST_HEAD(&red_eye->list);
    INIT_LIST_HEAD(&blue_eye->list);
    INIT_LIST_HEAD(&black_eye->list);
    INIT_LIST_HEAD(&green_eye->list);

    list_add_tail(&red_eye->list, &eyes);
    list_add_tail(&blue_eye->list, &eyes);
    list_add_tail(&black_eye->list, &eyes);
    list_add_tail(&green_eye->list, &eyes);

    struct eyes_t *counter;
    list_for_each_entry(counter, &eyes, list)
    {
        pr_info("%s eyes\n", counter->color);
    }


    return 0;
}

/* exit function */
static void __exit list_cleanup(void) {
    printk(KERN_INFO "[ Inside cleanup_module\n");
}

// static void sma_list(void) {

// }

module_init(list_init);
module_exit(list_cleanup);
MODULE_LICENSE("GPL");   
