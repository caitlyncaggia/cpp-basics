//------------------------------------------ Example 4

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream inFileExample("input.txt", ios::in);
int x;
int y;
bool goodInput;

//checking to see if we opened the file
if (inFileExample == false) //note that we could also use -- if (!inFileExample)
cout << "Error in opening the file" << endl;
else
{
inFileExample >> x >> y;
goodInput = inFileExample;
while (goodInput) //first use of a while loop like in MATLAB
{
cout << "x = " << x << " y = " << y << endl;
goodInput = inFileExample >> x >> y; // notice combination
}

}

inFileExample.close(); //This closes the file object 
}

