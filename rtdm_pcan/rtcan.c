#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <rtdm/rtdm.h>

int pcan_fd0;
int pcan_fd1;
int pcan_fd2;
static int __init rtcan_init(void)
{
	const char device0[] = "pcan0"; 
	const char device1[] = "pcan1"; 
	const char device2[] = "pcan2"; 
	pcan_fd0 = rt_dev_open(device0, 0);
	pcan_fd1 = rt_dev_open(device1, 0);
	pcan_fd2 = rt_dev_open(device2, 0);
	printk(KERN_INFO "[rtcan] pcan0 file descriptor: %i\n",pcan_fd0);
	printk(KERN_INFO "[rtcan] pcan1 file descriptor: %i\n",pcan_fd1);
	printk(KERN_INFO "[rtcan] pcan2 file descriptor: %i\n",pcan_fd2);
	printk(KERN_INFO "[rtcan] succesfully loaded\n");

	return 0;
}

static void __exit rtcan_exit(void)
{
	int retval0;
	int retval1;
	int retval2;
	retval0 = rt_dev_close(pcan_fd0);	
	retval1 = rt_dev_close(pcan_fd1);	
	retval2 = rt_dev_close(pcan_fd2);	
	printk(KERN_INFO "[rtcan] pcan0 closed with exit code: %i\n",retval0);
	printk(KERN_INFO "[rtcan] pcan0 closed with exit code: %i\n",retval1);
	printk(KERN_INFO "[rtcan] pcan0 closed with exit code: %i\n",retval2);
	printk(KERN_INFO "[rtcan] succesfully unloaded\n");
}

module_init(rtcan_init);
module_exit(rtcan_exit);

MODULE_AUTHOR("Peter Kotvan");
MODULE_LICENSE("GPL");
