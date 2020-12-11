#include "gthread.h"
#include <iostream>

using namespace std;

gthread_mutex_t mutex;
gthread_mutex_t mutex1;
int*            globalCount;

void MyThread1(const char* hello, int i)
{
  LockMutex(mutex);
  cout << hello << " int i s " << i << endl;
  UnlockMutex(mutex);
  EndThread();
}


void MyThread(int myId, int count1, int count2)
{
  int myCount = 0;
  for (int i = 0; i < count1; ++i)
    {
      LockMutex(mutex);
        {
          
          cout << "Hello from thread " << myId
               << " i " << i << endl;
        }
      UnlockMutex(mutex);
      for (int j = 0; j < count2; ++j)
        {
          globalCount[myId]++;
        }
      
    }
  EndThread();
}

void DummyThreadNoArgs()
{
  // nothing to do here...
  LockMutex(mutex);
  cout << "Hello from DummyThreadNoArgs" << endl;
  UnlockMutex(mutex);
  EndThread();
}


int main(int argc, char** argv)
{
  if (argc < 4)
    {
      cout << "Not enough args, exiting" << endl;
      exit(1);
    }
  int nThreads = atol(argv[1]);
  int count1   = atol(argv[2]);
  int count2  =  atol(argv[3]);
  globalCount = new int[nThreads];

  // Check for zero args thread
  CreateThread(DummyThreadNoArgs);
  

  for (int i = 0; i < nThreads; ++i)
    {
      CreateThread(MyThread, i, count1, count2);
      //CreateThread(MyThread1, "Goodbye", count1);
    }
  WaitAllThreads();
  int total = 0;
  for (int i = 0; i < nThreads; ++i)
    {
      total += globalCount[i];
    }
  
  cout << "Count is " << total
       << " expected " << nThreads * count1 * count2 << endl;
  
}
