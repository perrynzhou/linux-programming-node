/*************************************************************************
  > File Name: cond.cc
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 05:51:24 2020
 ************************************************************************/

#include "cond.h"
Cond::~Cond()
{
  pthread_mutex_destroy(&m_mutex);
  pthread_cond_destroy(&m_cond);
}
int Cond::init()
{
  int ret = pthread_mutex_init(&m_mutex, nullptr);
  if (ret == 0)
  {
    ret = pthread_cond_init(&m_cond, nullptr);
  }
  if (ret != 0)
  {
    pthread_mutex_destroy(&m_mutex);
    return -1;
  }
  return 0;
}
inline bool Cond::wait()
{
  int ret = 0;
  pthread_mutex_lock(&m_mutex);
  ret = pthread_cond_wait(&m_cond);
  pthread_mutex_unlock(&m_mutex);
  return ret == 0;
}
inline bool Cond::signal()
{
  return pthread_cond_broadcast(&m_cond) == 0;
}