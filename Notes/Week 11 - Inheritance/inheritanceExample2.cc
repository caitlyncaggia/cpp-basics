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

   Base * BasePtr = &BaseObject;
   A * APtr = &AObject;
   B * BPtr = &BObject;
   C * CPtr = &CObject;

   Base * BaseAPtr = &AObject;
   Base * BaseBPtr = &BObject;
   Base * BaseCPtr = &CObject;

   //Let's call Func1() from every object through its own pointer
   cout << "Call the Func1() through its own pointer" << endl;
   BasePtr->Func1();
   APtr->Func1();
   BPtr->Func1();
   CPtr->Func1();

   //Let's call Func2() from every object through its own pointer
   cout << "Call the Func2() through its own pointer" << endl;
   BasePtr->Func2();
   APtr->Func2();
   BPtr->Func2();
   CPtr->Func2();

   //Let's call Func1() from every object through the BASE Pointer 
   cout << "Call the Func1() through the base pointer" << endl; 
   BasePtr->Func1();
   BaseAPtr->Func1();
   BaseBPtr->Func1();
   BaseCPtr->Func1();

   //Let's call Func2() from every object through the BASE Pointer 
   cout << "Call the Func2() through the base pointer" << endl; 
   BasePtr->Func2();
   BaseAPtr->Func2();
   BaseBPtr->Func2();
   BaseCPtr->Func2();
}

