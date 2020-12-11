#include <iostream>
using namespace std;

//class interface for DArray
class DArray
{
public:
   DArray(int);//constructor with one argument
   DArray(const DArray &);
   ~DArray(); //destructor prototype-- no arguments

   DArray & operator=(const DArray &);
   double & operator[](int) ; //function prototype
  
   //get functions
   int getSize() const {return(size);}
   double * getBeginPtr() const {return(beginPtr);}

private:
   int size; //size of dynamically allocated array
   double * beginPtr;
}; //end of class interface
//-----------------------

double & DArray::operator[](int subscript) 
{
  //check to see if the subscript is out of range
  if ( subscript <0 || subscript >= size) //then PROBLEM
  {
   cout << "Error with subscript range. Passing zero element." << endl;
   subscript = 0;
  } //end of if statement

   return(beginPtr[subscript]);

}//end of operator[]

//-----------------------
DArray::DArray(const DArray & arrayToCopy): size(arrayToCopy.size)
{ 
   //allocate the array for the new object
    beginPtr = new double[size];

   //copy over the values for the array
   for (int i = 0; i < size; i++)
       beginPtr[i] = arrayToCopy.beginPtr[i];

   //print out a message for education value
   cout << "Copy constructor called with size " << size << endl;

}//end copy constructor 

//-----------------------

DArray & DArray::operator=(const DArray & rhs)
{ 

 //Check for self-assignment  A=A;
  if (&rhs != this) 
  {  //assume not A=A;

   if ( size != rhs.size)
   {
       delete [] beginPtr; // delete array LHS
       //size = rhs.size; //copy over size
       size = rhs.getSize(); //copy over size
       beginPtr = new double[size];
   }//end of if not same size

   for (int i=0; i < size ; i++)
      beginPtr[i] = rhs.beginPtr[i];
  }//end if for self assignment
 
  return (*this);

}//end of assignment operator


//-----------------------
DArray::DArray(int len)
{
size = len;  // puts data into size data memberA

//dynamically allocate data
beginPtr = new double[size];

//initialize the array values to all zeros
for (int i=0; i < size; i++)
   beginPtr[i] = 0.0;

cout << "I have allocated the array with size " << size << endl;
}//end of constructor
//-----------------------
DArray::~DArray()
{
   delete [] beginPtr;  //prevents memory leaks

   cout << "I have deallocated the array of size" << size <<endl;
}//end of destructor

DArray negateArray(const DArray );

//global function prototype
void printContents(const DArray &);

int main()
{
  DArray objectSize10(10);
  DArray objectSize20(20);
  DArray objectSize30(30);
  DArray copyObject(objectSize30);

  objectSize20 = objectSize10;

  objectSize20[5] = 3.1415;

 // printContents(objectSize20);
} 

//---------------------------------------------
/*void printContents(const DArray & object)
{
   for (int i =0; i < object.getSize(); i++)
      cout << object[i] << endl;
}
*/








