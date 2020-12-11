#include <iostream>
using namespace std;

int fire = 2;

void DirectHit();

int main()
{
	int fire = -3;
	DirectHit();
	fire += 10;
	DirectHit();
	cout << fire <<endl;
}

void DirectHit()
{
	static int fire = -1;
	fire += 5;
	cout <<fire <<endl;
}