#include <linux/module.h>       // Needed by all modules
#include <linux/kernel.h>       // KERN_INFO
#include <linux/sched.h>        // for_each_process, pr_info
#include <asm/current.h>


void procs_info_print(void)
{
        // struct task_struct* task_list;
        // size_t process_counter = 0;
        // for_each_process(task_list) {
        //         pr_info("CMD= %s, PID= [%d], UID=[%d]\n", task_list->comm, task_list->pid, __kuid_val(task_uid(task_list)));
        //         ++process_counter;
        // }
        printk(KERN_INFO "== Number of process: %s\n", current->comm);
}

int init_module(void)
{
        printk(KERN_INFO "[ INIT ==\n");

        procs_info_print();

        return 0;
}

void cleanup_module(void)
{
        printk(KERN_INFO "== CLEANUP ]\n");
}

MODULE_LICENSE("GPL");


/*

__kuid_val(task_uid(task_list))                 https://stackoverflow.com/questions/13104803/is-there-a-way-to-find-out-what-user-owns-a-process-from-the-processs-task-stru/45798644#45798644



*/