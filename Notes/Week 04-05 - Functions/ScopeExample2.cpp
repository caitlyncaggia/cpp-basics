//This shows scope for global and local variables
#include <iostream>
using namespace std;

void localManipulate();
void staticManipulate();

int main()
{
int x = 500;

system ("clear");

cout << "Call at the begining of main" << endl;
cout << "look at x in main: x = " << x << endl;

cout << "Call staticManipulate" << endl;
staticManipulate();
cout << endl;

cout << "Call staticManipulate" << endl;
staticManipulate();
cout << endl;

cout << "Call localManipulate" << endl;
localManipulate();
cout << endl;

cout << "Call localManipulate" << endl;
localManipulate();
cout << endl;

cout << "look at x in main: x = " << x << endl;

}//end main

void staticManipulate()
{
   static int x=0;
   x = x +1;
   cout << "The static in staticManipulate variable is:  x = " << x << endl;
}

void localManipulate()
{
   int x=0;
   x = x +1;
   cout << "The local variable in localManipulate is:  x = " << x << endl;
}
