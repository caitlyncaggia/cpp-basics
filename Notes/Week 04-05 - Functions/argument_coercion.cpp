#include <iostream>
#include <string>

using namespace std;

int add_three_int(int, int, int);
double add_three_double(double, double, double);

int main()
{
double num1,num2,num3;

char name='c'; 

num1 = 6.8;
num2 = 12.4;
num3 = 15.2;


cout << "number 1 " <<  num1 << endl;
cout << "number 2 " <<  num2 << endl;
cout << "number 3 " << num3 << endl;

cout << "sum of numbers: " << num1+num2+num3 << endl;

cout << "sum from int function with coercion: " << add_three_int(num1, num2, num3) << endl;


}

int add_three_int(int num1, int num2, int num3)
{
   cout << "Inside the function of int's " << endl;
   cout << "num1 : " << num1 <<endl;
   cout << "num2 : " << num2 << endl;
   cout << "num3 : " << num3 << endl;

   return( num1+num2+num3);
}

double add_three_double(double num1, double num2, double num3)
{
   cout << "Inside the function of int's " << endl;
   cout << "num1 : " << num1 <<endl;
   cout << "num2 : " << num2 << endl;
   cout << "num3 : " << num3 << endl;

   return( num1+num2+num3);
}
