#include <linux/module.h>
#include <linux/kernel.h>
//#include "./pridavok.h"

void pridavok(void);
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
