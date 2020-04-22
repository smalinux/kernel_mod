#include <linux/module.h>    /*included for all kernel modules*/
#include <linux/kernel.h>    /*included for KERN_DEBUG*/
#include <linux/init.h>      /*included for __init and __exit macros*/
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

#define MY_USB_VENDOR_ID 0x0930
#define MY_USB_PRODUCT_ID 0x6544
static struct usb_device_id my_usb_table[] = {
       { USB_DEVICE(MY_USB_VENDOR_ID, MY_USB_PRODUCT_ID) },
       {},
};
MODULE_DEVICE_TABLE(usb, my_usb_table);

static int
my_pdrv_probe(struct usb_interface *pdev, const struct usb_device_id *id) {
    pr_err("Hello\n");
    return 0;
}

static void my_pdrv_remove(struct usb_interface *pdev) {
    pr_err("Bye\n");
}

static struct usb_driver mypdrv = {
    .name = "my first usb driver",
    .id_table = my_usb_table,
    .probe = my_pdrv_probe,
    .disconnect = my_pdrv_remove,
};
// module_usb_driver(mypdrv);

static int __init my_pdev_init(void)
{
    int result;

    pr_err("Hello Guy\n");
    /* Refister with kernel  */
    result = usb_register(&mypdrv);
    if (result < 0) {
        pr_err("usb_register failed for the "__FILE__ "driver."
            "Error number %d", result);
        return -1;
    }

    return 0;
}

static void __exit my_pdev_remove(void)
{
    pr_err("Bye Guy\n");
    /* Unregister from kernel */
    usb_deregister(&mypdrv);
}

module_init(my_pdev_init);
module_exit(my_pdev_remove);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sohaib Mohammed");
MODULE_DESCRIPTION("first usb driver module");
MODULE_VERSION("0.1");