#include <linux/module.h>
#include <linux/kernel.h>
#include <rtai.h>
#include <rtai_sched.h>

extern RTIME Casovac;
extern RT_TASK RealTimeVlakno;
void cleanup_module(void)
{
  stop_rt_timer();
  rt_task_delete(&RealTimeVlakno);
  printk(KERN_INFO "Vyhadzujem modul\n");
}
