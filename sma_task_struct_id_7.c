#include <linux/module.h>
#include <linux/kernel.h>
// #include <asm/uaccess.h>
// #include <linux/fs.h> 
// #include <linux/cdev.h>
// #include <linux/proc_fs.h>
// #include <linux/pid.h>

// #include <linux/moduleparam.h>
// #include <linux/init.h>
// #include <linux/stat.h>
// #include <linux/slab.h>
// #include <linux/sched.h>        // for_each_process, pr_info

#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/tty.h>
#include <linux/signal_types.h>
#include <linux/signal.h>

#include <linux/pid_namespace.h>

int         p_id = 158533;
struct      pid *pid_struct;
struct      task_struct *task, *child;
struct      list_head *list;
char        tty[64];


static void list_task_struct(void) {
    printk(KERN_WARNING "================ Basic Info ================\n");
    pid_struct      = find_get_pid(p_id);
    task            = pid_task(find_get_pid(p_id),PIDTYPE_PID);

    printk(KERN_INFO "Proc name = %s ID: %d State = %ld\n", task->comm, task->pid, task->state);
    printk(KERN_INFO "Flags = %u\n", task->flags);


    printk(KERN_INFO "UID = %d\n", task->cred->uid);

    
    // printk(KERN_INFO "TTY = %s\n", task->signal->tty.tty);
    

    /*if (task->state == 0) // runnable
    {
        printk(KERN_INFO "State: runnable\n");
    } else if (task->state == -1) // unrunable
    {
        printk(KERN_INFO "State: unrunnable\n");
    } else {
        printk(KERN_INFO "State: stopped\n");
    }*/

    /* 
    PPID - Nice value
    =========================================
    */
    printk(KERN_INFO "Parent name = %s ID = %d\n", task->real_parent->comm, task->real_parent->pid);
    // printk(KERN_INFO "Parent of parent of parent name = %s\n", task->real_parent->real_parent->real_parent->comm);

    
    printk(KERN_INFO "Nice val = %d\n", task_nice(task));

    /* 
    Children
    =========================================
    */
    printk(KERN_WARNING "================ sibling ================\n");
    if (list_empty(&task->sibling)) { // Check if there are any sibling ? No?
        printk(KERN_INFO "Not have any brother :(( \n");
    } else {                        // Yes ?
        list_for_each(list, &task->sibling) {
            child=list_entry(list, struct task_struct, sibling);
            printk(KERN_INFO "== %s", child->comm);
        }
    }
    

    printk(KERN_WARNING "================ Children ================\n");
    if (list_empty(&task->children)) {
        printk(KERN_INFO "Not have any child :(( \n");
    } else {
        list_for_each(list, &task->children) {
            child=list_entry(list, struct task_struct, children);
            printk(KERN_INFO "== %s", child->comm);
        }
    }

    // =======================================================================

    printk(KERN_INFO "Thread ID == %u \n", task->thread_pid->level);
    // printk(KERN_WARNING "================ 'ptraced' ================\n");
    // if (list_empty(&task->ptraced)) {
    //     printk(KERN_INFO "Not have any child :(( \n");
    // } else {
    //     list_for_each(list, &task->ptraced) {
    //         child=list_entry(list, struct task_struct, ptraced);
    //         printk(KERN_INFO "ptraced == %s", child->comm);
    //     }
    // }

    printk(KERN_INFO "Login ID == %u \n", task->loginuid.val);
























}

static int __init proc_init (void) {
    list_task_struct();
    printk(KERN_INFO "\n");
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

