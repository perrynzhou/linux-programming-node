/*************************************************************************
  > File Name: sem.h
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 05:35:08 2020
 ************************************************************************/

#ifndef _SEM_H
#define _SEM_H
#include <semaphore.h>
class Sem
{
public:
  Sem() {}
  inline bool wait();
  inline bool post();
  inline int init();
  ~Sem();

private:
  sem_t m_sem;
};

#endif
