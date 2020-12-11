//This demonstrates mutex with STL of thread and mutex
//Davis Fall2013
//make sure you run this without mutex commands for comparisons
//also change inner for loop so that each process goes at differentj

#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <stdlib.h>

using namespace std;

mutex coutMutex;

void Thread1() 
{
   for (int i=0; i < 10; ++i)
   {
      coutMutex.lock();
      cout << "Hello from thread 1"<<endl;
      coutMutex.unlock();
      for (int j = 0; j < 10; ++j)
         { //consume time to slow this function down
         }
   }
}

void Thread2() 
{
   for (int i=0; i < 10; ++i)
   {
      coutMutex.lock();
      cout << "Hello from thread 2"<<endl;
      coutMutex.unlock();
      for (int j = 0; j < 10000; ++j)
         { //consume time to slow this function down
         }
   }
}
int main(int argc, char **argv)
{


   thread t1(Thread1);
   thread t2(Thread2);

   t1.join();
   t2.join();
   
   cout << "Main exiting now" << endl;
}



