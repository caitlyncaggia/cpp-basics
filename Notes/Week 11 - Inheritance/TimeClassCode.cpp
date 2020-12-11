#include <iostream>
#include <iomanip>
using namespace std;

//class interface
class Time
{
public:
   //illustrating concept 1. Constructor with default parameters
   Time(int = 0, int = 0, int = 0);

   //set functions
   void setTime(int,int,int);
   void setHour(int);
   void setMinute(int);
   void setSecond(int);

   //get functions
   int getHour();
   int getMinute();
   int getSecond();

   //general member functions
   void printTime();

private:
   int hour; //0-23 hours
   int minute; //0 to 59 
   int second; //0 to 59

}; //end of time class

//----------------------------
// implementation of class member functions
//----------------------------

//illustrating concept 1. Constructor with default parameters

Time::Time(int hr, int min, int sec)
{
   setTime(hr,min,sec);
   cout << "The time object ";
   printTime();
   cout << " has been created" << endl;
} //end of constructor

void Time::setTime(int hr, int min, int sec)
{
   setHour(hr);
   setMinute(min);
   setSecond(sec);
}//end setTime

void Time::setHour(int hr)
{

   if (hr >= 0 && hr <= 23)
      hour = hr;
   else
      cerr << "Error in hour input!! " << endl;
}

void Time::setMinute(int min)
{
   if (min >=0 && min <=59)
      minute = min;
   else
      cerr << "Error in minutes input!!" <<endl;
} //end of setMinute

void Time::setSecond(int sec)
{
   if (sec >=0 && sec <=59)
      second = sec;
   else
      cerr << "Error in second input!!" <<endl;
} //end of setMinute

int Time::getHour()
{
   return hour;
}

int Time::getMinute()
{
   return minute ;
}

int Time::getSecond()
{
   return second;
}

void Time::printTime()
{
  //This prints the time with no newline character 
  cout << setfill('0') << setw(2) << getHour() << ":"
       <<setw(2) << getMinute() << ":"
       <<setw(2) << getSecond(); //no endl

}//end printTime


//--------------
// main function
//-------------

int main()
{
Time time1;
Time time2(21); //specify hour only
Time time3(21,45); //specify hour and minute
Time time4(3,30,30); //specify all!

return 0;
}

