#include <iostream>
using namespace std;

#define ARRAY_SIZE 10
const int array_size = 10;

void printArray(const int [], const int);
void initArray(int [], const int);

int main()
{
system("clear");

int array[array_size];

initArray(array,array_size);
printArray(array,array_size);

}

void initArray(int array[], const int size)
{

  for (int i =0;  i< size; i++)
  { 
      array[i] = -1; 
  }
}


void printArray(const int array[], const int size)
{

  for (int i =0;  i< size; i++)
  { 
      cout << array[i] << " " ;
  }
 // Question what happens if I try to call this function
  //initArray(array, size);
  cout << endl;
}

