#include <linux/module.h>
void pridavok(void)
{
  printk("Som v pridavku\n\n");
}

void nahrada(void)
{
  printk("Som v nahrade\n\n");
  pridavok();
}

EXPORT_SYMBOL(nahrada);