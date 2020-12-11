#include <iostream>
using namespace std;

template <typename T1, typename T2, typename T3>
T1 sumfunction( T2 param1, T3 param2)
{
return ( (T1) (param1 + param2));
}


int main()
{

double doubleNum1 = 4.8;
double doubleNum2 = 10.8;
int intNum1 = 2;
int intNum2 = 8;

system ("clear");

cout << "Mixing "<< doubleNum1 << " & " << intNum1  << endl;

cout << " Example with this mixing to return a double = " <<  sumfunction <double>(doubleNum1, intNum1) << endl;
cout << "Example with this mixing to return a int = " <<  sumfunction <int>(doubleNum1, intNum1) << endl;
cout << endl;

cout << "Mixing "<< doubleNum1 << " & " << doubleNum2  << endl;
cout << "Example with these doubles returning a double = " << sumfunction <double> (doubleNum1, doubleNum2) << endl;
cout << endl;

cout << "Mixing "<< intNum1 << " & " << intNum2  << endl;
cout << "Example with these ints and returning an int = " << sumfunction <int> (intNum1, intNum2) << endl;

return 0;

}
