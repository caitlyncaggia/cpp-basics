#include <iostream>
#include "ComplexNum.h"


using namespace std;

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

