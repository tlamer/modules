#include <rtai.h>
#include <rtai_sched.h>
void funkcia (long t)
{
  while(1)
  {
    rt_printk("Caovac\n\n");
    rt_task_wait_period();
    
  }
}