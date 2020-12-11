#include <iostream>
#include <iomanip>
using namespace std;

//class interface
class Time
{
public:
   //illustrating concept 1. Constructor with default parameters
   Time(int=0,int=0,int=0);
   //Time(int,int,int);
   //Time(int,int); //Can I have this one too?
   //Time();  //Can I have this one too?

   //set functions
   void setTime(int,int,int);
   void setHour(int);
   void setMinute(int);
   void setSecond(int) ;

   //get functions
   int getHour() const; 
   int getMinute() const;
   int getSecond()const; 

   //general member functions
   void printTime() const; 

private:
   int hour; //0-23 hours
   int minute; //0 to 59 
   int second; //0 to 59
   const int lunchHour; //can't initialize in old standard
   //You can initialize this constant in the INITIALIZE LIST
   // associated with the constructor

}; //end of time class

//----------------------------
// implementation of class member functions
//----------------------------

//illustrating concept 1. Constructor with default parameters
//illustrating initializer list and constants
Time::Time(int hr, int min, int sec) : lunchHour(12), hour(hr)
//Time::Time(int hr, int min, int sec) 
{
   setTime(hr,min,sec);
   cout << "The time object (with constructor 1) ";
   printTime();
   cout << " has been created" << endl;
} //end of constructor

//Can I have this one too?
/*
Time::Time(int hr, int min)
{
   setTime(hr,min,59);
   cout << "The time object (with constructor 2) ";
   printTime();
    cout << " has been created" << endl;
} */

//Can I have this one too?
//Time::Time()
//{
//    setTime(0,0,0);
//    cout << "The time object with the default constructor ";
//    printTime();
//    cout << "has been created" << endl;
//}

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

int Time::getHour() const
{
   return hour;
}

int Time::getMinute() const 
{
   return minute ;
}

int Time::getSecond() const
{
   return second;
}

void Time::printTime() const
{
   //try to reset seconds to zero
   //setSecond(0); //This gives an error because it is a non-const MF

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
system ("clear");

Time time1;
Time time2(21); //specify hour only
Time time3(21,45); //specify hour and minute
Time time4(3,30,30); //specify all!
const Time lunchTime(12,30,0);

//I cannot do the following code without making changes
//The question is why?
cout << "The lunch hour is: " << lunchTime.getHour() << endl;
lunchTime.printTime();
cout << endl;
return 0;
}











