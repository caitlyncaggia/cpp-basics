#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char * * argv)
{
	if (argc != 2)
	{ cout << "Please name input" << endl; }
	else
	{
		cout < "The filename is: " << argv[1] <<endl;
			
		//now define input file object and variables
		ifstream inputFile( argv[1], ios::in);
		int width, height;
		string trash; //in the input file, the first thing on the line is a string you won't use
		
		if(inputFile) //if true, all is okay
		{
			cout << "Found the file... going forward" << endl;
			
			inputFile >> trash >> width;
			inputFile >> trash >> height;
			cout << "The width is : " << width << endl;
			cout << "The height is: " << height << endl;
			
			//create a 2D array
			int * * arrayPtr;
			arrayPtr = new int *[height]; //setting up array of int pointers
			for (int i = 0; i < height; i++)
				{
					arrayPtr[i] = new int [width];
				}
			//fill in the array -- initialize the array
			for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < width; j++)
						arrayPtr[i][j] = 1;
				}
			
			//fill in output text file
			ofstream outputFile("output.dat", ios::out);
			for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < width; j++)
						outputFile << arrrayPtr[i][j] << " ";
						outputFile << endl;
				}
									
			inputFile.close(); //next time you open the file, it will start reading from the top
			outputFile.close();
			
			delete arrayPtr //?
			
		}
		else
		{ cout << "Error in opening file!" << endl;}
	}

}