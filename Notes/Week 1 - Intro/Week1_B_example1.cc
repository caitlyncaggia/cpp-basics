//------------------------------------------ Example 1
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
cout << "Hello" << endl;
cout << setw(15) << "Hello" << endl;
cout << "Hello" << endl;
cout << setw(15) << "Hello" << "Hello" <<endl;

//example of sticky

cout << setfill('*');
cout << setw(15) << "Hello" << endl;
cout << setw(30) << "Hello" << endl;
return 0;

}

