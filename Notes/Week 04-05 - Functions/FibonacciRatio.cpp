#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long int Fibonacci(int);


int main()
{
int number;
long int nthFibonacci;
long int nminus1Fibonacci;

cout << "How far to you want to go in the Fibonnacci series? >> " ;
do
{
cin >> number;
} while (number < 2);

cout << setprecision(10);

nthFibonacci = Fibonacci(number);
nminus1Fibonacci = Fibonacci(number-1);
cout << "The " << number <<"th Fibonnaci number is " << nthFibonacci << endl;
cout << "The " << number-1 <<"th Fibonnaci number is " << nminus1Fibonacci << endl;
cout << "The ratio of the nth to the (n-1)th is : " << (double) nthFibonacci/nminus1Fibonacci << endl;

cout << endl;
cout << "The golden ratio is defined as (1+sqrt(5))/2 = " << (1+sqrt(5))/2 << endl;
return 0;
}

long int Fibonacci(int num)
{

   switch(num)
   {
      case 1: return(0);
      case 2: return(1);
      default: return (Fibonacci(num-2) + Fibonacci(num-1));
   }
}
