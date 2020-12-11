#include <iostream>
using namespace std;

class PeanutButter
{
public:
	PeanutButter(float creamy) {CreamyFactor = creamy;}
	PeanutButter() {CreamyFactor = 5.0;}
	float getCreamyFactor() {return(CreamyFactor);}
	PeanutButter operator%(PeanutButter);
private:
	float CreamyFactor;
};

PeanutButter PeanutButter::operator%(PeanutButter RHS)
{
	float average = .5*(getCreamyFactor()+RHS.getCreamyFactor());
	return (PeanutButter(average));
}

int main()
{
	PeanutButter PeanutButterA(5.0);
	PeanutButter PeanutButterB(3.0);
	PeanutButter MixOfAandB;

	MixOfAandB = PeanutButterA%PeanutButterB;
	cout << "The mix of PeanutButter A and B gives a new peanut butter with a creamy factor equal to: " 	
    <<MixOfAandB.getCreamyFactor()<<endl;
}