//This will have an example of a switch statement
#include <iostream> 
#include <iomanip>
using namespace std;

//function prototype for printGrades
void printGrades(int,int,int,int);

int main()
{

int aCount=0, bCount=0, cCount =0, dCount =0;
char grade;

system("clear");
cout << "Please input your grades A,B,C,D" << endl;


while ( (grade = cin.get()) != EOF) //cntrol-d on mac and control-z PC 
{

   switch(grade)
   {
      case 'A':
      case 'a':
         aCount++;
         break;
      case 'B':
      case 'b':
         bCount++;
         break;
      case 'C':
      case 'c':
         cCount++;
         break;
      case 'D':
      case 'd':
         dCount++;
         break;
      case '\n':
      case ' ':
         break;
      default:
         cout <<"You did not enter a correct grade" << endl;
   } //end of switch statementS
} //end of while loop

printGrades(aCount,bCount,cCount,dCount);

return 0;

} //end of main


void printGrades(int numA, int numB, int numC, int numD)
{

   cout << "The summary of your grades are as follows" << endl;
   cout << "\n\n";
   cout << "Number of A's: " << numA <<endl;
   cout << "Number of B's: " << numB <<endl;
   cout << "Number of C's: " << numC <<endl;
   cout << "Number of D's: " << numD <<endl;

}









