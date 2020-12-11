//------------------------------------------ Example 3
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ofstream outputFileExample("output.txt", ios::out);
//ios::out deletes current contents of files
//ios::app this will append to the file

int number = 10;

outputFileExample << "Hello File!!" << endl;
outputFileExample << number << endl;

outputFileExample.close();  //This is an interesting function call that 
// we have not cover yet... 

return 0;
}

