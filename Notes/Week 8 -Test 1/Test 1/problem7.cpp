#include <iostream>
using namespace std;

void SieveofEratosthenese(bool *, int);
void Print(bool *, int);
void CreateArray(bool *&, int);
void DeleteArray(bool *);

int main()
{
	bool *boolArray = NULL;
	int size;
	cout << "Please input the size of the boolean array" <<endl;
	cin >> size;
	CreateArray(boolArray, size);
	SieveofEratosthenese(boolArray, size);
	Print(boolArray, size);
	DeleteArray(boolArray);
}

void CreateArray(bool *&boolArray, int size)
{
	boolArray = new bool [size];
	for(int i=0; i<size; i++)
	{
		boolArray[i] = 1;
	}
}

void DeleteArray(bool *boolArray)
{
	delete [] boolArray;
}

void SieveofEratosthenese(bool *boolArray, int size)
{
	if (size >=2)
	{
		for(int i = 2; i<size/2; i++)
		{
			for(int j = 2*i; j<size; j++)
			{
				boolArray[j] = false;
			}
		}
	}
}

void Print(bool *boolArray, int size)
{
	for(int i =2; i<size; i++)
	{
		if(boolArray[i])
			cout <<i<<" ";
		cout <<endl;
	}
}
