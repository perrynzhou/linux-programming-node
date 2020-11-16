/*************************************************************************
  > File Name: cond.h
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 05:51:15 2020
 ************************************************************************/

#ifndef _COND_H
#define _COND_H
#include <pthread.h>
class Cond
{
public:
  Cond() {}
  ~Cond();
  bool init();
  bool wait();
  bool signal();

private:
  pthread_mutex_t m_mutex;
  pthread_cond_t m_cond;
};
#endif
