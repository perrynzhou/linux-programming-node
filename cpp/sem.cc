/*************************************************************************
  > File Name: sem.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 05:35:19 2020
 ************************************************************************/

#include "sem.h"
#include <stdio.h>
inline bool Sem::wait()
{
  return sem_wait(&m_sem) == 0;
}
inline bool Sem::post()
{
  return sem_post(&m_sem) == 0;
}
inline int Sem::init()
{
  return sem_init(&m_sem, 0, 0);
}
Sem::~Sem()
{
  sem_destroy(&m_sem);
}
