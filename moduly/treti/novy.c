#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
  printk(KERN_INFO "Nacitavam modul\n");
  return(0);
}

void cleanup_module(void)
{
  printk(KERN_INFO "Vyhadzujem modul\n");
}