#include <iostream>
#include <fstream>
#include <list>
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
	list <WordUnit> wordList;
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
			
			bool getout = false;
			list <WordList>::iterator curr = wordList.begin();
			
			//check to see if the word is in the vector
			while (!getout)
			{
				if (curr == wordList.end()) //at end of list
				{
					getout = true;
					WordList.push_back(WordUnit(tempString.1)); //list also has a push back function. Yay reuseability
				}
				else if ((*curr).getWord() == tempString)
				{
					++(*curr); //use overloaded increment
					getout = true;
				}
				else if ((*curr).getWord() > tempString)
				{
					getout = true;
					wordList.insert(curr, WordUnit(tempString, 1));
				}
				else
				{
					curr++;
				}
			} //end inner while
					
		} //end while
		
		//print out vector
		for (int i =-; i < wordList.size(); i++)
		{
			cout << wordList[i].getWord() << " " << wordList[i].getFrequency() << endl;
		}
		
	} //end if statement
	
} //end main