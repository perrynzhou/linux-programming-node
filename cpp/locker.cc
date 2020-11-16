/*************************************************************************
  > File Name: locker.cc
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 05:33:25 2020
 ************************************************************************/

#include "locker.h"

inline int  Locker::init() {
  return pthread_mutex_init(&m_mutex,nullptr);
}
inline bool Locker::lock() {
  return pthread_mutex_lock(&m_mutex) ==0;
}
inline bool Locker::unlock() {
  return pthread_mutex_unlock(&m_mutex)==0;
}
Locker::~Locker() {
  pthread_mutex_destroy(&m_mutex);
}


