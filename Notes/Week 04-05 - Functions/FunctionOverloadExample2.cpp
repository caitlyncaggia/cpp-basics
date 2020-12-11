//This is an example of function overloading that is very similar to the book 
#include <iostream>
using namespace std;

int cube(int);
double cube(double);
float cube (float); 

int main()
{
double doubleVar = 7.8;
float floatVar = 2.3;
int intVar = 2;

cout << "Double call gives "<< cube(doubleVar) << " and size is " << sizeof(doubleVar) << " bytes" << endl;
cout << "Float call gives "<< cube(floatVar) << " and size is " << sizeof(floatVar) << " bytes" << endl;
cout << "Int call gives "<< cube(intVar) << " and size is " << sizeof(intVar) << " bytes" << endl;

}//end of main

int cube (int num)
{
   return( num*num*num);
}

double cube (double num)
{
   return( num*num*num);
}

float cube (float num)
{
   return( num*num*num);
}


