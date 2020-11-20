/*************************************************************************
    > File Name: kill_d.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: Friday, November 20, 2020 PM03:03:33
 ************************************************************************/

#include <linux/init.h>
#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/sched.h> 
#define KILLD_MAX_PROCESS  (1024)
MODULE_LICENSE("BSD");
static int n_pids;
static  int pids[KILLD_MAX_PROCESS] ={0};
module_param_array(pids, int, &n_pids, S_IRUGO);

static int killd_init(void)
{

  struct task_struct *p;
  int i = 0;
  printk(KERN_ALERT "********************welcome to use killd to kill  D status process*************\n");
  for (i = 0; i < n_pids; i++)
  {
    for_each_process(p)
    {
      if (p->pid == pids[i])
      {
        printk(KERN_ALERT "killd  %d process success\n",pids[i]);
        set_task_state(p, EXIT_DEAD);
        return 0;
      }
    }
  }
  return 0;
}
static void killd_exit(void)
{
  printk(KERN_ALERT "exit killd kernel module");
}
module_init(killd_init);
module_exit(killd_exit);
MODULE_AUTHOR("perrynzhou@gmail.com");
MODULE_DESCRIPTION("kill D status process");
MODULE_LICENSE("GPL");