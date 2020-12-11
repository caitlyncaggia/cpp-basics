//This is an example of code that using a do..while loop
#include <iostream>
#include <cstdlib>
#include <ctime>

#define FALSE 0 //define constants with preproccessor
#define TRUE 1

using namespace std;

int main()
{

int guess;
int random_number;
int seed;

system("clear");
//cout << "Please input a random seed: ";
//cin >> seed;

//This is the starting seed to generate random numbers
//srand(seed);

srand(time(0));

random_number = 1+ (rand() % 6) ; //new mod function

cout << "Please enter a number from 1 to 6: ";

//now perform some error checking on the input
do
{
   cin >> guess;

   if ( (guess <1) || (guess >6))
       cout << "Your number is out of range! Please enter again from 1 to 6: ";

}while (guess <1 || guess > 6);

cout << "\n\n";

if (guess == random_number)
   cout << "You won!!" << endl;
else
   cout << "You lost!! The number was " << random_number << endl;

cout << (rand() %6);

return 0;
} //end main 
