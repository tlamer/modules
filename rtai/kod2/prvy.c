#include <linux/module.h>
#include <linux/kernel.h>
#include <pridavok.h>
#include <rtai.h>
#include <rtai_sched.h>

RT_TASK RealTimeVlakno;
extern void funkcia(long);
RTIME Casovac;

int init_module(void)
{
  
  printk(KERN_INFO "Nacitavam modul\n");
  //pridavok();
  //nahrada();
  //Casovac=start_rt_timer(nano2count(4700*28)); // Spustenie casovaca
  Casovac=start_rt_timer(nano2count(4700)); // Spustenie casovaca
  
  rt_task_init(&RealTimeVlakno,funkcia,0,3000,15,0,0);
  rt_task_make_periodic(&RealTimeVlakno,rt_get_time()+nano2count(1000000000),nano2count(1000000000));
  printk(KERN_INFO "Nacitavam modul koniec\n");
  return(0);
}

