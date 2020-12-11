#include <iostream>
using namespace std;
class A{
 public:
  A(); // Default constructor
  A(int); // int Constructor
  A(const A&); // Copy constructor
  ~A(); // Destructor
  A operator+(const A& rhs) const; // Addition operator
 public:
  int x; // Single data member
};
A::A(): x(0){ cout<<"A Def Con     "<<endl; };
A::A(int x): x(x){ cout<<"A Int Con    "<<endl; };
A::~A(){ cout<<"-A Destructor     "<<endl; };
A::A(const A &a){
 x=a.x;
cout<<"A Copy Con   "<<endl;
};
 A A::operator+(const A& rhs) const
{
 cout<<"A +     "<<endl;
 A r(x + rhs.x);
return r;
}
class B{
 public:
  B(); // Default Constructor
  B(int); // int Constructor
  B(const B&); // Copy constructor
  ~B(); // Destructor
  B operator+(B rhs) const; // Addition operator
 public:
  int x; // Single data member
};
B::B(): x(0){ cout<< "B Def Con   "<<endl;};
B::B(int x): x(x){ cout<< "B Int Con   "<<endl;};
B::~B(){ cout<< "-B Destructor     "<<endl;};
B::B(const B &b){
 x=b.x;
 cout<<"B Copy Con      "<<endl;
};
 B B::operator+(B rhs) const
{
 cout<< "B +  "<<endl;
 return B(x + rhs.x);
}
 int main()
{
  A a;
  B b(2);
  B c(b);
  a = a + a;
  b = b + c;
  cout << a.x << " " << b.x <<endl;
}
