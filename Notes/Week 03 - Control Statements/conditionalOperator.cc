#include <iostream>
using namespace std;

int main()
{

double Temp;


cout << "Please enter your car temperature: ";
cin >> Temp;


cout << "The engine is " << (Temp >= 300 ? "in danger" : "safe. ") << endl;

return 0;
}
