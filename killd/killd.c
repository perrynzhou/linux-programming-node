/*************************************************************************
    > File Name: kill_d.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: Friday, November 20, 2020 PM03:03:33
 ************************************************************************/
#define _POSIX_SOURCE

#include <linux/kernel.h>
#include <linux/unistd.h>

#include <linux/init.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/version.h>

#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/signal.h> 
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/cred.h>
#define SYS_KILL_NR 62
MODULE_LICENSE("BSD");
static  int pid;
module_param(pid, int,  S_IRUGO);
unsigned long *syscall_table;

/* asmlinkage -> expect arguments on the stack */
/* declare a function pointer to the original sys_kill */
asmlinkage long (*orig_sys_kill)(int pid, int sig);

asmlinkage long kill_proces(int pid, int sig)
{
	printk(KERN_ALERT "[%s] :)\n", "killd module");
	return (*orig_sys_kill)(pid, sig);
}


static int killd_init(void)
{
  struct task_struct *p;
  orig_sys_kill = (asmlinkage long (*) (int, int)) syscall_table[SYS_KILL_NR];
	syscall_table[SYS_KILL_NR] = (unsigned long) kill_proces;
  printk(KERN_ALERT "********************welcome to use killd to kill  D status process*************\n");
  
    for_each_process(p)
    {
      if (p->pid == pid)
      {
        printk(KERN_ALERT "killd  %d process success\n",pid);
        set_task_state(p, TASK_INTERRUPTIBLE);
        kill_proces(p->pid,SIGKILL);
      }
    }
  
  return 0;
}
static void killd_exit(void)
{
	syscall_table[SYS_KILL_NR] = (unsigned long) orig_sys_kill;
  printk(KERN_ALERT "exit killd kernel module");
}
module_init(killd_init);
module_exit(killd_exit);