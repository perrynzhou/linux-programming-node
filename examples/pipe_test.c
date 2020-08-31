 /*************************************************************************
  > File Name: pipe_test.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 一  8/31 07:30:26 2020
************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/time.h>
int main(void)
{
  int fds[2];
  pipe(fds);
  pid_t pid = fork();
  if (pid > 0)
  {
    close(fds[0]);
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    int err;
    int i = 0;
    select(0, NULL, NULL, NULL, &tv);
    i++;
    write(fds[1], &i, sizeof(int));
    fprintf(stdout, "[parent pid =%d]write value:%d\n", getpid(), i);
    wait(NULL);
    close(fds[1]);
  }
  else if (pid < 0)
  {
    exit(-1);
  }
  else
  {
    close(fds[1]);
    int v;
    read(fds[0], &v, sizeof(int));
    fprintf(stderr, "[child pid=%ld] read value:%d\n", getpid(), v);
    close(fds[0]);
  }
  return 0;
}