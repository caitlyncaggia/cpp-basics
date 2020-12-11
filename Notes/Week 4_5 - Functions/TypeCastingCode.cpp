#include <iostream>
using namespace std;

int main()
{

double doubleNumber = 4.893;
int intNum1 = 5;
int intNum2 = 4;


cout << "The doubleNumber " << doubleNumber << " cast to an int " << (int) doubleNumber << endl;
cout << "The ratio of intNum1 to intNum2 "<< intNum1 << "/" << 
intNum2 << " with no casting " << intNum1/intNum2 << endl;
cout << "The ratio of intNum1 to intNum2 " << intNum1 << "/" << 
intNum2 << " cast to double " << ((double) intNum1)/intNum2 << endl;

//remember play with the last one to make a point!
return 0;

}
