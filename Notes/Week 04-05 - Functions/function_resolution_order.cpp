#include <iostream>
#include <string>
using namespace std;

string left_string();
string right_string();
void print_combined(string,string);


int main()
{

system("clear");

print_combined(left_string(), right_string());

}

string left_string()
{
 cout << "left side" << endl;
 return ("left string");
}
string right_string()
{
 cout << "right side" << endl;
 return ("right string");
}
void print_combined(string str1, string str2)
{
 cout << str1 << " " << str2 << endl;
}


