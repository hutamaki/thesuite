#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <pthread.h>

namespace OS
{
  class Mutex
  {
    public:
      Mutex() 
      { 
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&mutex, &attr);
      }
      void lock() { pthread_mutex_lock(&mutex); }
      void unlock() { pthread_mutex_unlock(&mutex); }
    private:
      pthread_mutex_t mutex;
      pthread_mutexattr_t attr;
  };

  class ScopedMutex
  {
    public:
      ScopedMutex() { mutex.lock(); }
      ~ScopedMutex() { mutex.unlock(); }
    private:
      Mutex mutex;
  };
}

#endif
