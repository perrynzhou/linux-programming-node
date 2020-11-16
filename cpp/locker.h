/*************************************************************************
  > File Name: locker.h
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 05:33:20 2020
 ************************************************************************/

#ifndef _LOCKER_H
#define _LOCKER_H
#include <pthread.h>
class Locker
{
public:
  Locker(){}
  inline int init();
  inline bool lock();
  inline bool unlock();
  ~Locker();

private:
  pthread_mutex_t m_mutex;
};
#endif
