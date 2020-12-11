//Remeber to toggle the virtual function
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
   void printHour();
   void printMinute();
   void printSecond();
   //virtual void printTime();
   void printTime();

private:
   int hour; //0-23 hours
   int minute; //0 to 59 
   int second; //0 to 59

}; //end of time class

class MilliTime : public Time
{
   public:
   MilliTime(int = 0, int = 0, int = 0, int=0);

   //set functions
   void setMilliSec(int);

   //get functions
   int getMilliSec();

   //general member functions
    void printMilliSec();
    void printTime();

   private:
   int milliSec; //0 to 999
}; //End of MilliTime

class MicroTime : public MilliTime
{
   public:
   MicroTime(int = 0, int = 0, int = 0, int = 0,int =0);

   //set functions
   void setMicroSec(int);

   //get functions
   int getMicroSec();

   //general member functions
    void printMicroSec();
    void printTime();

   private:
   int microSec; //0 to 999
}; //End of MicroTime

// --------------------------
MicroTime::MicroTime(int hr, int min, int sec, int milli, int micro) : MilliTime( hr, min, sec, milli), microSec(micro)
{ }

void MicroTime::setMicroSec (int micro)
{
   if (micro >= 0 && micro <= 999)
      microSec = micro;
   else
      cerr << "microsecond input is invalid";
}//end set MillitSec

int MicroTime::getMicroSec()
{ return microSec; }

void MicroTime::printMicroSec()
{ cout << setw(2) << getMicroSec(); }

void MicroTime::printTime()
{
   MilliTime::printTime();
   cout << ":" ;
   printMicroSec();
}


// --------------------------
MilliTime::MilliTime(int hr, int min, int sec, int milli) : Time( hr, min, sec), milliSec(milli)
{ }

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

void MilliTime::printMilliSec()
{
cout << setw(2) << getMilliSec(); //no endl
}

void MilliTime::printTime()
{
   Time::printTime(); // This will access the printTime  in Time Class

   /*printHour();
   cout << ":";
   printMinute();
   cout << ":";
   printSecond();*/

   cout << ":";
   printMilliSec();
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

void Time::printHour()
{ cout << setw(2) << getHour() ; }

void Time::printMinute()
{ cout << setw(2) << getMinute(); }

void Time::printSecond()
{ cout << setw(2) << getMinute(); }

void Time::printTime()
{
	printHour();
	cout << ":";
	printMinute();
	cout << ":";
	printSecond();
}//end printTime


//--------------
// global function prototype
//-------------
void PrintThroughPointer(Time *);
void PrintThroughReference(Time &);

//--------------
// main function
//-------------

int main()
{

Time TimeObject(1,10,10);
MilliTime MilliObject(2,20,20,200);
MicroTime MicroObject(3,30,30,300,300);
system ("clear");

//Show that derived class can access its own print function
cout << endl;
cout << "(Base) Time Object in Main Function" <<endl;
TimeObject.printTime();
cout << endl;

//Show that base class can access its own print function
cout << "(Derived) Milli Object Main Function" <<endl;
MilliObject.printTime();
cout << endl;

//Show that base class can access its own print function
cout << "(Derived) Micro Object Main Function" <<endl;
MicroObject.printTime();
cout << endl;

cout << "Print TimeObject through pointer in function" << endl;
PrintThroughPointer(&TimeObject);

cout << "Print MilliObject through pointer in function" << endl;
PrintThroughPointer(&MilliObject);

cout << "Print MicroObject through pointer in function" << endl;
PrintThroughPointer(&MicroObject);

cout << "Print TimeObject through reference in function" << endl;
PrintThroughReference(TimeObject);

cout << "Print MilliObject through reference in function" << endl;
PrintThroughReference(MilliObject);

cout << "Print MicroObject through reference in function" << endl;
PrintThroughReference(MicroObject);

return 0;
}

void PrintThroughPointer(Time * pointer)
{
  pointer->printTime();
  cout << endl;
}

void PrintThroughReference(Time & reference)
{
   reference.printTime();
   cout << endl;
}
