#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init test2_init(void)
{
	printk(KERN_INFO "[test2] loading\n");
	return 0;
}

static void __exit test2_exit(void)
{
	printk(KERN_INFO "[test2] unloading\n");
}

module_init(test2_init);
module_exit(test2_exit);
