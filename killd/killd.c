/*************************************************************************
    > File Name: kill_d.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: Friday, November 20, 2020 PM03:03:33
 ************************************************************************/
#define _POSIX_SOURCE

#include <linux/kernel.h>
#include <linux/unistd.h>

#include <linux/module.h>
#include <linux/init.h>

#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/init.h>
#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/signal.h> 
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/cred.h>
MODULE_LICENSE("BSD");
static  int pid;
module_param(pid, int,  S_IRUGO);
static int killd_init(void)
{
  struct task_struct *p;
  int signum;
  struct siginfo info;
  int ret;
  printk(KERN_ALERT "********************welcome to use killd to kill  D status process*************\n");
  
    for_each_process(p)
    {
      if (p->pid == pid)
      {
        printk(KERN_ALERT "killd  %d process success\n",pid);
        set_task_state(p, TASK_INTERRUPTIBLE);
        signum = SIGKILL;
        memset(&info, 0, sizeof(struct siginfo));
        info.si_signo = signum;
        ret = send_sig_info(signum, &info, p);
        if (ret < 0) {
            printk(KERN_INFO "error sending signal\n");
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