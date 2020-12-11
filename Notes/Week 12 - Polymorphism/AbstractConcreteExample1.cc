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
void test1() { cout << "Hello from Derived1 - test1" << endl ; }
};

class Derived2 : public Base
{
public:
void test1() { cout << "Hello from Derived2 - test1" << endl ; }
};

class Derived3 : public Base
{ 
public:
void test1() { cout << "Hello from Derived3 - test1" << endl ; }
};

int main()
{

 Derived1 Object1;
 Derived2 Object2;

 Object1.test();

}

