//this will illustrate for loop and scope issues
#include <iostream>
using namespace std;

int main()
{

int i=5;
int j=12;

system("clear");

i = 5;
j = 12;


for (int i=1; i <= 10; i++)  //comment out the int to see how things change
{
cout << "The counter number is " << i <<endl;
}

cout << "out of the loop we have i = " << i << endl;

{
int j;

j = 8;

cout << "Inside the block... j = " << j <<endl;
}

cout << "the j declared in main is = " << j << endl;

return 0;
}
