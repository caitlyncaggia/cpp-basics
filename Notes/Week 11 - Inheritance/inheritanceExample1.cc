#include <iostream>
using namespace std;
class Base
{ // Define a base class
 public:
  void Func1();
  void Func2(); 
  void Func3();
  void Func4();
};
//------------------------
class A : public Base
{ // Class A derives from Base
 public:
  void Func2();
  void Func4();
};
//------------------------
class B : public A
{// Class B derives from A
 public:
  void Func1();
  void Func4();
 };
//------------------------
class C : public Base
 { // Class C derives from Base
 public:
  void Func1();
  void Func4();
 };
//------------------------
 // Base Class Methods
 void Base::Func1() { cout << "Hello from Base::Func1()" << endl; }
 void Base::Func2() { cout << "Hello from Base::Func2()" << endl; }
 void Base::Func3() { cout << "Hello from Base::Func3()" << endl; }
 void Base::Func4() { cout << "Hello from Base::Func4()" << endl; }
 // Class A Methods
 void A::Func2() { cout << "Hello from A:Func2()" << endl; }
 void A::Func4() { cout << "Hello from A:Func4()" << endl; }
 // Class B Methods
 void B::Func1() { cout << "Hello from B:Func1()" << endl; }
 void B::Func4() { cout << "Hello from B:Func4()" << endl; }
 // Class C Methods
 void C::Func1() { cout << "Hello from C:Func1()" << endl; }
 void C::Func4() { cout << "Hello from C:Func4()" << endl; }

 int main()
 { Base BaseObject;
   A  AObject;
   B  BObject;
   C  CObject;

   //Let's call Func1() from every object
   cout << "Call the Func1() from every object" << endl;
   BaseObject.Func1();
   AObject.Func1();
   BObject.Func1();
   CObject.Func1();

   //Let's call Func2() from every object
   cout << "Call the Func2() from every object" << endl;
   BaseObject.Func2();
   AObject.Func2();
   BObject.Func2();
   CObject.Func2();

   //Let's call Func3() from every object
   cout << "Call the Func3() from every object" << endl;
   BaseObject.Func3();
   AObject.Func3();
   BObject.Func3();
   CObject.Func3();

   //Let's call Func4() from every object
   cout << "Call the Func4() from every object" << endl;
   BaseObject.Func4();
   AObject.Func4();
   BObject.Func4();
   CObject.Func4();

}

