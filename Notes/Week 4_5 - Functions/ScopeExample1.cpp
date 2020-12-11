//This shows scope for global and local variables
#include <iostream>
using namespace std;

int x = 1000;

void globalManipulate();
void localManipulate();

int main()
{
int x = 500;

system ("clear");

cout << "Call at the begining of main" << endl;
cout << "look at x in main: x = " << x << endl;

cout << "look at x in main with unary resolution operator : x = " << ::x << endl;

cout << "Call globalManipulate" << endl;
globalManipulate();
cout << "look at x in main with unary resolution operator : x = " << ::x << endl;
cout << endl;


cout << "Call globalManipulate" << endl;
globalManipulate();
cout << "look at x in main with unary resolution operator : x = " << ::x << endl;
cout << endl;

cout << "Call localManipulate" << endl;
localManipulate();
cout << "look at x in main with unary scope: x = " << ::x << endl;

cout << "look at x local to main x = " << x << endl;

}//end main

void globalManipulate()
{
  //There is no x in its local scope so it uses global scope
   x = x +1;
}

void localManipulate()
{
   int x;

   x = x +1; // manipulates the local varaible x
}
