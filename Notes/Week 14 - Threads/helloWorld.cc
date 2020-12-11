#include <iostream>
#include "gthread.h"

using namespace std;

void hello()
{
   cout << "Hello Concurrent World!" << endl;
   EndThread();
}

int main()
{


CreateThread(hello);
WaitAllThreads();

}//end main

