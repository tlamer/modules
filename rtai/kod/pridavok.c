#include <linux/module.h>
#include <math.h>
void pridavok(void)
{
  long i;
  printk("Som v pridavku\n\n");
  for (i=0;i<(pow(2,25));i++)
  {
    printk("Som v pridavku:%ld\n\n",i);
  }
  
}

void nahrada(void)
{
  printk("Som v nahrade\n\n");
  pridavok();
}

EXPORT_SYMBOL(nahrada);