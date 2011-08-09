#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/moduleparam.h>

MODULE_AUTHOR("Peter Kotvan");
MODULE_LICENSE("GPL");

static short int shrt=1;
static int nt=123;
static long int lng=10000;
static char *str="foobar";
static int ntarray[2]={-1,-2};
static int arr_argc;

module_param(shrt, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );
MODULE_PARM_DESC(shrt, "short int");
module_param(nt, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
MODULE_PARM_DESC(nt, "short int");
module_param(lng, long, S_IRUSR);
MODULE_PARM_DESC(lng, "long int");
module_param(str, charp, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );
MODULE_PARM_DESC(lng, "long int");

module_param_array(ntarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(ntarray, "int array");

static int __init test3_init(void)
{
	int i;
	printk(KERN_INFO "[test3] hello world!\n============\n");
	printk(KERN_INFO "[test3] short: %hd\n", shrt);
	printk(KERN_INFO "[test3] int: %d\n",nt);
	printk(KERN_INFO "[test3] long: %ld\n",lng);
	printk(KERN_INFO "[test3] str: %s\n",str);
	for (i=0;i<(sizeof ntarray / sizeof(int)); i++){
		printk(KERN_INFO "[test3] int array[%d]: %d\n",i, ntarray[i]);
	}
	printk(KERN_INFO "[test3] number of args: %d\n",arr_argc);
	
	return 0;
}

static void __exit test3_exit(void)
{
	printk(KERN_INFO "[test3] goodbye world!");
}

module_init(test3_init);
module_exit(test3_exit);

