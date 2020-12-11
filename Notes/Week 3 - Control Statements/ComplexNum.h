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

