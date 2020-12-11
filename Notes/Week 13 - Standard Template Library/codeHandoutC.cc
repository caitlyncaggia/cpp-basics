#include <iostream>
#include <string>
using namespace std;

int main()

{
string stringObject;
int location;

getline(cin, stringObject);
cout << stringObject << endl;

cout << "---------------------" << endl;
cout << "Example of using find" << endl;
if ((location = stringObject.find("example"))==string::npos)
   cout << "Not found in string" << endl;
else
   cout << location << endl;


cout << "---------------------" << endl;
cout << "Example of using rfind" << endl;
if ((location = stringObject.rfind("example"))==string::npos)
   cout << "Not found in string" << endl;
else
   cout << location << endl;


cout << stringObject.substr(1,5) << endl;
stringObject.erase(1,5);
cout << stringObject << endl;

stringObject.insert(1,"test");
cout << stringObject << endl;


}
