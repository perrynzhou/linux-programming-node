/*************************************************************************
  > File Name: thread_pool.cc
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 二 11/17 06:02:57 2020
 ************************************************************************/

#include "thread_pool.h"
template <typename T>
ThreadPool<T>::ThreadPool(uint32_t count, uint32_t max_requests, RequestHandler handler) : m_thread_count(count), m_max_requests(max_requests), m_handler(handler)
{
}
template <typename T>
ThreadPool<T>::~ThreadPool()
{
  if (m_threads != nullptr)
  {
    delete[] m_threads;
  }
}
template <typename T>
void ThreadPool<T>::stop()
{
  m_stop = true;
}
template <typename T>
bool ThreadPool<T>::append(T *t)
{
  m_lock.lock();
  if (m_requests.size() >= m_max_requests)
  {
    m_lock.unlock();
    return false;
  }
  m_requests.push_back(t);
  m_lock.unlock();
  m_sem.post();
  return true;
}
template <typename T>
void *ThreadPool<T>::worker(void *arg)
{
  ThreadPool *pool = static_cast<ThreadPool *>(arg);
  pool->run();
  return nullptr;
}

template <typename T>
int ThreadPool<T>::init()
{
  m_threads = new pthread_t[m_thread_count];
  assert(m_threads != nullptr);
  assert(m_lock.init() != 0);
  assert(m_sem.init() != 0);
  int ret = -1;
  for (int i = 0; i < m_thread_count; i++)
  {
    pthread_create(&m_threads[i], nullptr, worker, this);
  }
}
template <typename T>
void ThreadPool<T>::run()
{
  while (!m_stop)
  {
    if (m_stop)
    {
      break;
    }
    m_sem.wait();
    m_lock.lock();
    if (m_requests.empty())
    {
      m_lock.unlock();
      continue;
    }
    m_lock.unlock();
    T *t = m_requests.pop_front();
    m_handler(t);
  }
}
