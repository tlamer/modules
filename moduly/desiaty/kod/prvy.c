#include <linux/module.h>
#include <linux/kernel.h>
#include <pridavok.h>

int init_module(void)
{
  printk(KERN_INFO "Nacitavam modul\n");
  //pridavok();
  nahrada();
  printk(KERN_INFO "Nacitavam modul koniec\n");
  return(0);
}

