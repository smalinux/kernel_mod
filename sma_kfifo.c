/*  
 *  sma_kfifo.c - The simplest queue example.
 *	
 *		kfifo_from_user
 *		kfifo_to_user
 *	
 *		Check rule: always out < in
 *	
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/kfifo.h>

/* fifo size in elements (bytes) */
#define FIFO_SIZE	32 			/* size must be a power of two.  */

static const unsigned char expected_result[FIFO_SIZE] = {
	 3,  4,  5,  6,  7,  8,  9,  0,
	 1, 20, 21, 22, 23, 24, 25, 26,
	27, 28, 29, 30, 31, 32, 33, 34,
	35, 36, 37, 38, 39, 40, 41, 42,
};

static struct kfifo test;

static int __init testfunc(void);

static int __init sma_hello(void)
{
	int ret;

	ret = kfifo_alloc(&test, FIFO_SIZE, GFP_KERNEL);
	if (ret) {
		pr_info("error kfifo_alloc\n");
		return ret;
	}

	if (testfunc() < 0) {
		kfifo_free(&test);
		return -EIO;
	}
	
	return 0;
}

static void __exit sma_bye(void)
{
	pr_info("Goodbye world\n");
	kfifo_free(&test);
}


static int __init testfunc(void)
{
	unsigned char	buf[6];
	unsigned char	i, j;
	unsigned int	ret;

	printk(KERN_INFO "byte stream fifo test start\n");

	/* put string into the fifo */
	kfifo_in(&test, "hello", 5);

	/* put values into the fifo */
	for (i = 0; i != 10; i++)
		kfifo_put(&test, i);

	/* show the number of used elements */
	printk(KERN_INFO "fifo len: %u\n", kfifo_len(&test));

	/* get max of 5 bytes from the fifo */
	i = kfifo_out(&test, buf, 5);
	printk(KERN_INFO "buf: %.*s\n", i, buf);

	/* get max of 2 elements from the fifo */
	ret = kfifo_out(&test, buf, 2);
	printk(KERN_INFO "ret: %d\n", ret);
	/* and put it back to the end of the fifo */
	ret = kfifo_in(&test, buf, ret);
	printk(KERN_INFO "ret: %d\n", ret);

	/* skip first element of the fifo */
	printk(KERN_INFO "skip 1st element\n");
	kfifo_skip(&test);

	/* put values into the fifo until is full */
	for (i = 20; kfifo_put(&test, i); i++)
		;

	printk(KERN_INFO "queue len: %u\n", kfifo_len(&test));

	/* show the first value without removing from the fifo */
	if (kfifo_peek(&test, &i))
		printk(KERN_INFO "%d\n", i);

	/* check the correctness of all values in the fifo */
	j = 0;
	while (kfifo_get(&test, &i)) {
		printk(KERN_INFO "item = %d\n", i);
		if (i != expected_result[j++]) {
			printk(KERN_WARNING "value mismatch: test failed\n");
			return -EIO;
		}
	}
	if (j != ARRAY_SIZE(expected_result)) {
		printk(KERN_WARNING "size mismatch: test failed\n");
		return -EIO;
	}
	printk(KERN_INFO "test passed\n");

	return 0;
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