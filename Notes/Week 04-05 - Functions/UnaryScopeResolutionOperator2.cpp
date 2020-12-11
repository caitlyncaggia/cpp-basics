#include <iostream>
using namespace std;

int number = 7;  // This is a global definition

int main()
{

int number = 10;

cout  << "The local value is " << number <<endl;
cout << "The global value is " << ::number << endl;

return 0;

}
