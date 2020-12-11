//This includes the example of a template  -- maybe show modification in class
#include <iostream>
using namespace std;

template <typename T>
T cube (T num)
{ 
   return( num*num*num);
}

int main()
{
double doubleVar = 7.8;
float floatVar = 2.3;
int intVar = 2;

cout << "Double call gives "<< cube(doubleVar) << " and size is " << sizeof(doubleVar) << " bytes" << endl;
cout << "Float call gives "<< cube(floatVar) << " and size is " << sizeof(floatVar) << " bytes" << endl;
cout << "Int call gives "<< cube(intVar) << " and size is " << sizeof(intVar) << " bytes" << endl;

}//end of main


