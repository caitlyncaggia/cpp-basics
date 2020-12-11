#include <iostream>
using namespace std;
class Base
{ // Define a base class
 public:
  virtual void Func1() = 0;
  virtual void Func2(); 
  virtual void Func3();
  void Func4();
};
class A : public Base
{ // Class A derives from Base
 public:
  void Func2();
  void Func4();
};
class B : public A
{// Class B derives from A
 public:
  virtual void Func1();
//  void Func2();
//  void Func4();
 };
class C : public Base
 { // Class C derives from Base
 public:
  virtual void Func1();
  virtual void Func4();
 };
 // Base Class Methods
 void Base::Func2(){ cout << "Hello from Base::Func2()" << endl;}
 void Base::Func3()
 {
 cout << "Hello from Base::Func3()" << endl;
 Func2(); // DON'T MISS THIS CALL IN YOUR ANSWER
 }
 void Base::Func4(){ cout << "Hello from Base::Func4()" << endl;}
 // Class A Methods
 void A::Func2() { cout << "Hello from A:Func2()" << endl; }
 void A::Func4() { cout << "Hello from A:Func4()" << endl; }
 // Class B Methods
 void B::Func1() { cout << "Hello from B:Func1()" << endl; }
 //void B::Func2() { cout << "Hello from B:Func2()" << endl; }
 //void B::Func4() { cout << "Hello from B:Func4()" << endl; }
 // Class C Methods
 void C::Func1() { cout << "Hello from C:Func1()" << endl; }
 void C::Func4() { cout << "Hello from C:Func2()" << endl; }
 void TestFunc(Base& x)
 {
  x.Func1();
  x.Func2();
  x.Func3();
  x.Func4();
 }
 int main()
 { //can't call Base or A because they are abstract
   B b,objectb;
   C c;
   cout << "Call Object B through base reference in function" << endl;
   TestFunc(b);
   cout << "Call Object C through base reference in SAME function" << endl;
   TestFunc(c);
   cout << "Now call functions from the object " << endl;
   objectb.Func1();
   objectb.Func2();
   objectb.Func3();
   objectb.Func4();
}

