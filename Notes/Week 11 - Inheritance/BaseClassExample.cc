#include <iostream>
using namespace std;

//Let's keep everything in the same file

class A //This will be the base class
{
public:

   void setA(int);
   int getA();
   virtual void print();
   void printA();

private:
   int A_data;
};

void A::setA(int value)
{ A_data = value; }
int A::getA()
{ return A_data; }
void A::print()
{ cout << "This is the A class " << endl;}
void A::printA()
{ cout << "This is the A data = " << A_data<< endl;}
//------
class B: public A //This will be a derived class
{
public:

   void setB(int);
   int getB();
   void print();

private:
   int B_data;
};
void B::setB(int value)
{ B_data = value; }
int B::getB()
{ return B_data; }
void B::print()
{ cout << "This is the B class " << endl;}
//------
class C: public B //This will be a derived class
{
public:

   void setC(int);
   int getC();
//   void print();

private:
   int C_data;
};
void C::setC(int value)
{ C_data = value; }
int C::getC()
{ return C_data; }
//void C::print()
//{ cout << "This is the C class " << endl;}
//----
int main()
{
  C objectC;
  A * objectBasePtr;

  objectC.print();
  objectC.printA();
  objectC.A::print();

  objectBasePtr = &objectC;

  cout << " Access print through the base pointer "  << endl;
  objectBasePtr->A::print();
  return 0;
}
