/*  
 *  sma_chardev.c - Full example of character device driver.
 *	step 1: Hello, world!
 * 	step 2: Allocating and registering a character device.
 */
#include <linux/init.h>
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/fs.h>	/* alloc_chrdev_region & unregister_chrdev_region */
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h> /*  */

#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/tty.h>
#include <linux/signal_types.h>
#include <linux/signal.h>

#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/pid_namespace.h>


#define SMA_DEVICE_NAME "sma_chardev"
#define SMA_CLASS_NAME "sma_class"

static unsigned int major; /* major number for device */
static struct class *sma_class;
static struct cdev sma_cdev;
static dev_t sma_devt = 0;		/* mix of ma & mi */
// static dev_t dev_num = 0;
// static unsigned int sma_pid;

int dummy_open(struct inode * inode, struct file * filp);
int dummy_release(struct inode * inode, struct file * filp);
ssize_t dummy_read (struct file *filp, char __user * buf, size_t count, loff_t * offset);
ssize_t dummy_write(struct file * filp, const char __user * buf, size_t count, loff_t * offset);
static void list_task_struct(int);

struct file_operations sma_fops = {
    open:       dummy_open,
    release:    dummy_release,
    read:       dummy_read,
    write:      dummy_write,
};

/* Allocating and registering My character
device */
static int register_ma_mi(void) {
	struct device *sma_device;
	int error;

	/* Alloc char device */
	error = alloc_chrdev_region(&sma_devt, 0, 1, SMA_DEVICE_NAME);
	if (error < 0)
	{
		pr_err("Failed to allocate chrdev region\n");
		return error;
	}

	major = MAJOR(sma_devt);	/* get major num */
    pr_info("sma_chardev major number = %d\n",major);

	/* Let's create our class, visible in /sys/class  */
	sma_class = class_create(THIS_MODULE, SMA_CLASS_NAME);

	if (IS_ERR(sma_class)) {
		pr_err("Error creating sma_class.\n");
		unregister_chrdev_region(MKDEV(major, 0), 1);
		return PTR_ERR(sma_class);
    }

	/* Tie file_operations to cdev */
	cdev_init(&sma_cdev, &sma_fops);
	sma_cdev.owner = THIS_MODULE;

	/* Make the device live for the users to access */
	cdev_add(&sma_cdev, sma_devt, 1);

	/* Create a device node device /dev/sma_chardev
	*  with our class used here.
	*  device can also be viewed under /sys/class/eep-class.
	*/
	sma_device = device_create(sma_class,
		NULL,			/* no parent device */
		sma_devt,
		NULL,			/* no additonal data */
		SMA_DEVICE_NAME);	/* device name */

	pr_info("sma_chardev module is loaded.\n");
	return error;
}

static int __init sma_init(void)
{
	int callback;
	callback = register_ma_mi();	/* Rigister Major & Minor numbers */

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	/* Failed to allocate chrdev region */
	return callback;
}

static void __exit sma_exit(void)
{
	unregister_chrdev_region(MKDEV(major, 0), 1);
    device_destroy(sma_class, MKDEV(major, 0));
    cdev_del(&sma_cdev);
    class_destroy(sma_class);

    pr_info("sma_chardev module Unloaded\n");
}

int dummy_open(struct inode * inode, struct file * filp)
{
    pr_info("Someone tried to open me\n");
    return 0;
}

int dummy_release(struct inode * inode, struct file * filp)
{
    pr_info("Someone closed me\n");
    return 0;
}

ssize_t dummy_read (struct file *filp, char __user * buf, size_t count, loff_t * offset)
{
	pr_info("Someone tried to open me\n");
    return 0;
}


ssize_t dummy_write(struct file * filp, const char __user * buf, size_t count, loff_t * offset)
{
	char temp_str[10];
	int sma_pid;
    int ret;
    struct task_struct *task;

    /* NEVER TRUST USER INPUT */
    if (count > 10)
        return -EINVAL;

    if (copy_from_user(temp_str, buf, 10) != 0)
        return -EFAULT;

    ret = sscanf(temp_str, "%u", &sma_pid);
    if (ret != 1) {
        pr_info("Error in reading PID value from user");
        return -EINVAL;
    }

    pr_info("User entered pid %u\n", sma_pid);
    task = pid_task(find_vpid(sma_pid), PIDTYPE_PID);
    if (task == NULL) {
        pr_info("Cannot find PID from user program\r\n");
        return -ENODEV;
    } else {
    	list_task_struct(sma_pid);
    }

    return count;
}
/* Takes PID & Prints all info of that PID */
static void list_task_struct(int p_id) {
	struct      pid *pid_struct;
	struct      task_struct *task, *child;
	struct      list_head *list;
	int tmp = 0;

    pid_struct      = find_get_pid(p_id);
    task            = pid_task(find_get_pid(p_id),PIDTYPE_PID);

    /* Proc name - PID - state */
    pr_info("Proc name = %s ID: %d State = %ld\n", task->comm, task->pid, task->state);
    pr_info("Flags = %u\n", task->flags);

    /* UID */
    pr_info("UID = %u\n", task->cred->uid.val);

    /* PPID - Nice value */
    pr_info("Parent name = %s ID = %d\n", task->real_parent->comm, task->real_parent->pid);
    // pr_info("Parent of parent of parent name = %s\n", task->real_parent->real_parent->real_parent->comm);

    pr_info("Nice val = %d\n", task_nice(task));

    /* sibling */
    if (list_empty(&task->sibling)) { // Check if there are any sibling ? No?
        pr_info("Not have any brother :(( \n");
    } else {                        // Yes ?
    	tmp = 0;
        list_for_each(list, &task->sibling) {
            child=list_entry(list, struct task_struct, sibling);
            pr_info("brother %d== %s", ++tmp, child->comm);
        }
    }

    /* Children */
    if (list_empty(&task->children)) {
        pr_info("Not have any children :(( \n");
    } else {
    	tmp = 0;
        list_for_each(list, &task->children) {
            child=list_entry(list, struct task_struct, children);
            pr_info("child %d== %s", ++tmp, child->comm);
        }
    }

    pr_info("Thread ID == %u \n", task->thread_pid->level);
    pr_info("Login ID == %u \n", task->loginuid.val);
}

module_init(sma_init);
module_exit(sma_exit);

/** MODULE_
*/
MODULE_AUTHOR("Sohaib (smalinux) <xunilams@gmail.com>");
MODULE_INFO(mylove,"Coffee & programming");	/* :D */
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("I'm trying to make module acts like ps -aux command.\
	takes PID as a write() syscall & prints proc info in de");
MODULE_LICENSE("GPL");