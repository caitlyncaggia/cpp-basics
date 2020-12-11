#include <iostream>
using namespace std;

unsigned long int factorial_iterative(int);

int main ()
{
   int number;

   cout << "Please input a number " ;
   cin >> number;

   cout << "The factorial of this number is " << factorial_iterative(number) << endl;

}//end main 

unsigned long int factorial_iterative(int number)
{
   unsigned long int total = 1;
   int i;

   
   for (i = number; i >= 1 ; i--)
   {
      total *= i;
   }   

   return (total); 

}// end factorial_iterative
