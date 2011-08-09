#include <rtai.h>
#include <rtai_sched.h>
void funkcia (long t)
{
  while(1)
  {
    rt_printk("RTAI casovac\n");
    rt_task_wait_period();
    
  }
}
