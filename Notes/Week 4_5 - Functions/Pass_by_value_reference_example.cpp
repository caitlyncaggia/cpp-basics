#include <iostream>
using namespace std;

double roundByValue(double);
void roundByReference(double &);
int main()
{

double input_number;

cout << "Please input a number to be rounded: " ;
cin >> input_number;

cout << "Using roundByValue function " << endl;
cout << "The number " << input_number << " rounded is = " << roundByValue(input_number) <<endl;
cout << "The variable input_number is = " << input_number << " after the call" <<endl;
cout << "\n\n\n\n" ;

cout << "Using roundByReference function " << endl;
cout << "The number " << input_number ;
roundByReference(input_number);
cout << " rounded is = " << roundByValue(input_number) <<endl;
cout << "The variable input_number is = " << input_number << " after the call" <<endl;


}

double roundByValue(double num)
{
   num = ( num >=0 ? (int) (num+0.5) : (int) (num-0.5));
   return (num);
}

void roundByReference(double &num)
{
   num = ( num >=0 ? (int) (num+0.5) : (int) (num-0.5));
   return;
}

