#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

double T; //This is a temperature


cout << "Please enter the current temperature: ";
cin >> T;

cout << fixed << setprecision(3) << "Temperature : " << T << "F" << endl;
//cout << scientific<< setprecision(3) << "Temperature : " << T << "F" << endl;

if (T >= 60 && T <= 100) // For this time of year this is most probable
	cout << "It is a nice day! " << endl;
else if (T >= 35 && T < 60)
	cout << "It is a little nippy! " << endl;
else if (T > 100 && T <= 120)
	cout << "Oh Boy! It's hot" << endl;
else if (T >= -40 && T < 35)
	cout << "I can't feel my toes!!" <<endl;
else
	cout << "Are you sure you are on planet earth!" << endl;

return 0;

}//end main
