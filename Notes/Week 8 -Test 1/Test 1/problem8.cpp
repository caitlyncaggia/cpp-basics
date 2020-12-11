#include <iostream>
using namespace std;

class Whatever
{
public:
	Whatever(){x=4; z = 'C';}
	int getX(){return (x);}
	char getZ(){return (z);}
	void narly();
private:
	int x;
	char z;
};

void Whatever::narly()
{
	z = x+z+2;
	x++;
}

void notFunny(Whatever);

int main()
{
	Whatever dude;
	for(int i = 1; i<=2; i++)
	{
		dude.narly();
		cout <<dude.getZ() << " ";
	}
	cout << endl;
	for(int i = 1; i<=2; i++)
	{
		notFunny(dude);
		cout <<dude.getX() << " ";
	}
	cout <<endl;
}

void notFunny(Whatever happened)
{
	happened.narly();
}
	