#include <iostream>
#include "ComplexNum.h"

using namespace std;


int main()
{
ComplexNumber object1;
ComplexNumber object2(3,10); //constructor call with arguments
ComplexNumber object3;

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
