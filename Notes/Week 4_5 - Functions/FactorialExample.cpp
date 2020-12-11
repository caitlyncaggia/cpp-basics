#include <iostream>
using namespace std;

unsigned long int factorial( int);

int main()
{
  int number;

  cout << "Please input your number : " ;
  cin >> number;

  cout << "The factorial of this number is: " << factorial(number) << endl;

  return 0;
}

unsigned long int factorial(int num)
{
   if (num == 1)
      return 1;
   else
      return( factorial(num-1)*num);

}

