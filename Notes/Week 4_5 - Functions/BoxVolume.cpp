#include <iostream>
#include <cmath>
using namespace std;


//function prototypes
int boxVolume (int = 1, int = 1, int = 1);

int main()
{
system ("clear");

cout << "Default Box value: " << boxVolume() << endl;

cout << "Box value with length = 3: " << boxVolume(3) << endl;

cout << "Box value with length = 3 && width = 4: " << boxVolume(3,4) << endl;

cout << "Box value with length = 3 && width = 4 && height = 2: " << boxVolume(3,4,2) << endl;

return 0;

}//end main


int boxVolume (int length, int width, int height)
{
   return (length*width*height);
}
