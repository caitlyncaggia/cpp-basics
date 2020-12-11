#include <iostream>
using namespace std;

class Base
{
public:
virtual void test() = 0;

};

class Derived1 : public Base
{
public:
void test() { cout << "Hello from Derived1 - test" << endl ; }
};

class Derived2 : public Base
{
public:
void test() { cout << "Hello from Derived2 - test" << endl ; }
};

class Derived3 : public Base
{ 
public:
void test() { cout << "Hello from Derived3 - test" << endl ; }
};

void globalFunctionEx(Base & objectPassed)
{
   objectPassed.test();
}
int main()
{

 Derived1 Object1;
 Derived2 Object2;

 globalFunctionEx(Object1);
 globalFunctionEx(Object2);

}

