#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

struct WordUnit
{
	string word;
	int frequency;
};

int main(int argc, char * * argv) //two ** is a pointer to a pointer, or can use char * argv[]
{
	vector <WordUnit> wordList;
	string tempString;
	WordUnit tempWordUnit; 
	
	if (argc == 2) //there are two elements on command prompt: a.out and input text file
	{
		
		ifstream inputFile (argv[1], ios::in);
		
		while (inputFile >> tempString)
		{
			//want to ignore punctuation
			int beginErase;
			if ( (beginErase = tempString.find_first_of("?!,.-")) != string::npos) //string::npos is the -1 at the end of the string
			{
				//then punctuation exists
				tempString.erase(beginErase, string::npos)
			}
			
			//want to ignore words with first letter capitalized
			tempString[0] = tolower(tempString[0]);
			
			int counter = 0;
			bool getout = false;
			//check to see if the word is in the vector
			while (!getout)
			{
				if (counter >= wordList.size()) //at end of list
				{
					getout = true;
					tempWordUnit.word = tempString;
					tempWordUnit.frequency = 1;
					wordList.push_back(tempWordUnit);
				}
				else if (wordList[counter].word == tempString)
				{
					wordList[counter].frequency++;
					getout = true;
				}
				else
				{
					counter++;
				}
			}
			
			//testing stage 1
			//cout << tempString << endl;
			
			//put into the vector
			tempWordUnit.word = tempString;
			tempWordUnit.frequency = 1;
			wordList.push_back(tempWordUnit);
			
			
		} //end while
		
		//print out vector
		for (int i =-; i < wordList.size(); i++)
		{
			cout << wordList[i].word << " " << wordList[i].frequency << endl;
		}
		
	} //end if statement
	
} //end main