#include <iostream>
using namespace std;

class ComplexNumber // class interface for ComplexNumber
{

public:  //public access specifier

//These are the member function prototypes
ComplexNumber();
ComplexNumber(float, float);
void setReal(float); 
void setImag(float);
void setComplex(float , float );
float getReal();
float getImag();
void printNum();

private:  //private access specifier

float real;
float imag;

};


ComplexNumber::ComplexNumber()
{ //constructor is used to initialize data
  real = 0.0;
  imag = 0.0;
}

ComplexNumber::ComplexNumber(float r, float i)
{  real = r; imag = i; }

void ComplexNumber::setReal(float r)
{ real = r; }

void ComplexNumber::setImag(float i)
{ imag = i; }

void ComplexNumber::setComplex(float r, float i)
{ //real = r; imag = i; 
  setReal(r); //good programming practice to reuse code
  setImag(i);
}

float ComplexNumber::getReal()
{ return (real); }

float ComplexNumber::getImag()
{ return(imag); }


void ComplexNumber::printNum()
{
cout << real << " +j" << imag << endl;
}

int main()
{
ComplexNumber object1;
ComplexNumber object2(3,10); //constructor call with arguments

//object1.real = 3;  //Example error of using privat date incorrectly
//object2.real = 10;

/* object1.setReal(3); //Example of using member functions to access data
object2.setReal(10);
object1.setImag(0);
object2.setImag(0);  */ //see multiple line comment

//cout << object1.getReal() << endl;
//cout << object2.getReal() << endl;

object1.printNum();
object2.printNum();

}
