#include <iostream>
using namespace std;

int main()
{

int score = 121;

switch(1)
{

case  (int) (score> 120 && score< 125):
   cout << "This is between 120 and 125 " << endl;
   break;

case (int)(score > 125 && score < 140):
   cout << "This is between 125 and 140" << endl;
   break;
default:
   cout << "This is out of range" << endl;

}//end switch statment

}//end main
