#include <iostream>
using namespace std;

int hidingName(int);

int main()
{
	for (int i = 1; i<=8; i++)
		cout << hidingName(i) << " ";
	cout<<endl;
}

int hidingName(int input)
{
	switch(input)
	{
		case 1: return (0);
		case 2: return (1);
		default: return (hidingName(input-2)+hidingName(input-1));
	}
}
	