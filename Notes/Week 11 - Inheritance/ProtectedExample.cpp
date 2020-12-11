#include <iostream>
#include <iomanip>
using namespace std;

//class interfaces

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
   // virtual void printTime();
   //void printTime();
   void printTime();

protected:
   int hour; //0-23 hours
   int minute; //0 to 59 
   int second; //0 to 59

}; //end of time class

class MilliTime : public Time
{
   public:
   MilliTime(int = 0, int = 0, int = 0, int = 0);

   //set functions
   void setMilliSec(int);

   //get functions
   int getMilliSec();

   //general member functions
   //virtual void printTime();
   //void printTime();
    void printTime();

   protected:
   int milliSec; //0 to 999
}; //End of MilliTime

// --------------------------
MilliTime::MilliTime(int hr, int min, int sec, int milli) : Time( hr, min, sec), milliSec(0)
{
   setMilliSec(milli);  
   //cout << "New constructor ";
   //printTime();
   //cout << endl; 
}

void MilliTime::setMilliSec (int milli)
{
   if (milli >= 0 && milli <= 999)
      milliSec = milli;
   else
      cerr << "millisecond input is invalid";
}//end set MillitSec

int MilliTime::getMilliSec()
{
      return milliSec;
}

void MilliTime::printTime()
{
  cout << setfill('0') << setw(2) << getHour() << ":"
       //<<setw(2) << getMinute() << ":"
       <<setw(2) << minute << ":"
       <<setw(2) << second << ":"; //no endl
       //<<setw(2) << getMinute() << ":"
       //<<setw(2) << getSecond() << ":"; //no endl
   cout <<setw(2) << getMilliSec(); //no endl
}

//----------------------------
// implementation of class member functions
//----------------------------

//illustrating concept 1. Constructor with default parameters

Time::Time(int hr, int min, int sec)
{
   setTime(hr,min,sec);
//   cout << "The time object ";
 //  printTime();
  // cout << " has been created" << endl;
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
// MilliTime


//--------------
// main function
//-------------

int main()
{

MilliTime DerivedTime(3,30,30,300);
Time BaseTime(3,30,30);
MilliTime * DerivedPtr = NULL;
Time * BasePtr = NULL;

//Show that derived class can access its own print function
cout << endl;
cout << "(DERIVED) Inside Main Function" <<endl;
DerivedTime.printTime();
cout << endl;

//Show that base class can access its own print function
cout << endl;
cout << "(BASE)Inside Main Function" <<endl;
BaseTime.printTime();
cout << endl;
/*
//Advanced idea...
//We can point a base pointer to a derived class
BasePtr = &DerivedTime;

//With pointer it gets tricky...Access print time through base point
cout << endl;
cout << "(BASE PTR)Inside Main Function" <<endl;
BasePtr->printTime();
cout << endl;

//Can we access member functions of derived class through base class
// No! Only virtual functions! 
//cout << endl;
//cout << "(BASE PTR)->member function derived class" <<endl;
//cout << BasePtr->getMilliSec() << endl;
*/

return 0;
}






















