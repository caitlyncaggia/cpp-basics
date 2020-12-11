//Demonstration of gThreads.cc

#include <iostream>
#include "gthread.h"
#include <stdlib.h>

using namespace std;

//Gthread Mutexes MUST be in global memory
gthread_mutex_t coutMutex;

void MyThreadThreeArgs(int myId, int count1, int count2)
{
   for (int i=0; i < count1; ++i)
   {
      //LockMutex(coutMutex);
      cout << "Hello from thread " << myId << " count1 " << i << endl;
      //UnlockMutex(coutMutex);
      for (int j = 0; j < count2; ++j)
         {
         }
   }
   EndThread(); // Required by GThreads library
}

int main(int argc, char **argv)
{

   if (argc < 4)
   {
      cout << "Usage: need nThreads count1 count2" << endl;
      exit(1);
   }
   
   int nThreads = atol(argv[1]);
   int count1 = atol(argv[2]);
   int count2 = atol(argv[3]);

   for (int i = 0; i < nThreads; i++)
   {  //Start each thread
      CreateThread(MyThreadThreeArgs, i, count1, count2);
   }

   //Now wait for all to complete
   WaitAllThreads();
   cout << "Main exiting now" << endl;
}



