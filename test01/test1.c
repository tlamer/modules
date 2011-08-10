#include <linux/module.h>
#include <linux/kernel.h>


int init_module(void)
{
	printk(KERN_INFO "[test1] loading\n");
	printk(KERN_DEBUG "[test1] debug msg\n");
	printk(KERN_INFO "[test1] info msg\n");
	printk(KERN_NOTICE "[test1] notice msg\n");
	printk(KERN_WARNING "[test1] warning msg\n");
	printk(KERN_ERR "[test1] error msg\n");
	printk(KERN_CRIT "[test1] critical msg\n");
	printk(KERN_ALERT "[test1] alert msg\n");
	printk(KERN_EMERG "[test1] emergency msg\n");
	return 0;
	//return -1;
}

void cleanup_module(void)
{
	printk(KERN_INFO "[test1] unloading\n");
}
