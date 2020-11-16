/*************************************************************************
  > File Name: thread_pool.h
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 06:02:52 2020
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include <deque>
#include <functional>
#include <pthread.h>
#include <cstdint>
#include "sem.h"
#include "locker.h"
template <typename T>
class ThreadPool
{
public:
  typedef std::function<int(T *t)> RequestHandler;
  ThreadPool(uint32_t count,uint32_t max_requests,RequestHandler handler);
  ~ThreadPool();
  int init();
  void start();
  bool append(T *t);
  void stop();
  static void *worker(void *arg);
private:
  void run();
  pthread_t m_threads;
  uint32_t  m_thread_count;
  uint32_t m_max_requests;
  bool m_stop;
  Locker m_lock;
  Sem m_sem;
  std::deque<T *> m_requests;
  RequestHandler m_handler;
};
#endif
