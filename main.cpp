#include"Rational.h"

//test for negative values
//needs to handle b=2+a and b=a+2
//prefix and postfix do the same thing
//Make sure that denom is not zero

int main ()
{
	double pause;
	Rational rOne;
	Rational rTwo(rOne);
	Rational c(3), d(2, 3), e("2/4");

	cout<<c;
	cout<<d;
	cout<<e;
	cout<<rOne;
	cout<<rTwo;

	cin>>rOne;
	cout<<rOne<<endl;
	rOne+= 2;
	cout<<rOne<<endl;


	//starting testing
	cin>> pause;
}
	
