#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

class WordUnit
{
	public:
	WordUnit(string in, int num) : word(in), frequency(num) {}
	string getWord() const {return word;}
	int getFrequency() const {return(frequency);}
	bool operator<(const WordUnit &rhs)	const
	{
		if (frequency > rhs.frequency)
			return(true);
		else
			return(false);
	}
	WordUnit & operator++() //this is a preincrement - we return the updated object itself
	{
		frequency++;
		return(*this)
	}
	
	private:
	string word;
	int frequency;
};

int main(int argc, char * * argv) //two ** is a pointer to a pointer, or can use char * argv[]
{
	vector <WordUnit> wordList;
	string tempString;
	//WordUnit tempWordUnit; 
	
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
					WordList.push_back(WordUnit(tempString.1));
				}
				else if (wordList[counter].getWord() == tempString)
				{
					++wordList[counter]; //use overloaded increment
					getout = true;
				}
				else
				{
					counter++;
				}
			} //end inner while
					
		} //end while
		
		sort(wordList.begin(), wordList.end()); //use algorithm for class
		//print out vector
		for (int i =-; i < wordList.size(); i++)
		{
			cout << wordList[i].getWord() << " " << wordList[i].getFrequency() << endl;
		}
		
	} //end if statement
	
} //end main