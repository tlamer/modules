#include <linux/module.h>
void pridavok(void)
{
  printk("Som v pridavku\n\n");
}

EXPORT_SYMBOL(pridavok);