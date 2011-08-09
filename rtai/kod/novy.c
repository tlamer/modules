#include <linux/module.h>
#include <linux/kernel.h>
#include <pridavok.h>

int init_module(void)
{
  printk(KERN_INFO "Nacitavam modul\n");
  pridavok();
  return(0);
}

void cleanup_module(void)
{
  printk(KERN_INFO "Vyhadzujem modul\n");
}

MODULE_LICENSE("GPL");


MODULE_AUTHOR("\nPeter Fodrek\nSlovak University of Technology @ Bratislava\npeter.fodrek@stuba.sk\n\n");	
MODULE_DESCRIPTION("Demo module for several module attributes");
MODULE_INFO(srcversion, "verzia 1.0");