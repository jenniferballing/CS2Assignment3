#include "Rational.h"

//Overloaded Constructors
Rational::Rational()
{
	numerator=0;
	denominator=1;
	inWords= new char;
	inWords="\0";
}
Rational::Rational(int N)
{
	numerator=N;
}
Rational::Rational(int N, int D)
{
	numerator=N;
	denominator=D;
}
Rational::Rational (string W)
{
	inWords = W;
}

//Copy Constructor
Rational::Rational(const Rational &obj)
{
	cout<<"Inside the copy constructor..."<<endl;
	numerator=obj.numerator;
	denominator=obj.denominator;
	inWords = obj.inWords;
}

//Overloaded Assignment Operators
Rational& Rational::operator= (const Rational &rhs)
{
	//To keep it from copying itself (a=a)
	if(this!=&rhs)
	{
		cout<<"Inside the overloaded operator \'=\'"<<endl;
		
		//Assign the numerator
		numerator=rhs.numerator;
		
		//Assign the denominator
		denominator=rhs.denominator;
		
		//Assign the inWords
		inWords=rhs.inWords;
		
		return *this;
	}
	else
	{
		return *this;
	}
}
Rational& Rational::operator= (const int N)
{
	numerator= N;
	return *this;
}
Rational& Rational::operator= (const string W)
{
	//Change const string W into a char array
	inWords=W;
	return *this;
}

//Overloaded Arithmetic Binary Operators
Rational Rational::operator+(const Rational &obj)
{
	//Add num and denom
	numerator+=obj.numerator;
	denominator+=obj.denominator;

	//Create temps and simplify
	int& tempNum=numerator;
	int& tempDenom=denominator;

	Simplify(tempNum, tempDenom);
	
	return *this;			
}
Rational Rational::operator+(int N)
{
	//Convert int to a fraction over denom
	N*=denominator;
	numerator+=N;

	//Create temps and simplify
	int& tempNum=numerator;
	int& tempDenom=denominator;

	Simplify(tempNum, tempDenom);
	
	return *this;
}
Rational Rational::operator+(string W)
{
	int num, denom, rnum, rdenom, newNum, newDenom;
	
	//Parse string W
	stringstream ss(W);
	ss>>num;
	ss.ignore();
	ss>>denom;

	//Parse string inWords
	stringstream sr(inWords);
	sr>>rnum;
	sr.ignore();
	sr>>rdenom;

	//Add nums and denoms
	newNum = rnum+num;
	newDenom = rdenom+denom;

	//Create temps and simplify
	int& tempNum=newNum;
	int& tempDenom=newDenom;
	Simplify(tempNum, tempDenom);

	
	//Put it back into a string
	stringstream s2;
	s2<<newNum<<"/"<<newDenom;
	inWords=s2.str();

	return *this;
}

//Overloaded Compound Assignment Operators
Rational& Rational::operator+= (const Rational &obj)
{
	*this=*this+obj;
	return *this;
}
Rational& Rational::operator+=(int num)
{
	numerator=numerator+num;	
	return *this;
}
Rational& Rational::operator+=(string W)
{
	inWords = inWords + W;
	return *this;	
}

//Relational Operators
bool Rational::operator==(const Rational &obj)
{	
	if (numerator==obj.numerator)
	{
		if(denominator==obj.denominator)
		{
			if(inWords==obj.inWords)
			{
				return true;
			}
		}
	}
	return false;		
}
bool Rational::operator>(const Rational &obj)
{
	float objFrac, Frac;
	
	//Find the float value of the fractions
	objFrac=(float)obj.numerator/obj.denominator;
	Frac=(float)numerator/denominator;
	
	//Compare
	if(Frac>objFrac)
	{
		return true;
	}
	return false;
}

//Prefix Operator
Rational Rational::operator++()
{
	//Create temps
	int& tempNum=numerator;
	int& tempDenom=denominator;
	
	//Increment
	++numerator;

	//Simplify
	Simplify(tempNum, tempDenom);
	
	return *this;	
}

//Postfix operator
Rational Rational::operator++(int)
{
	//Create temps
	int& tempNum=numerator;
	int& tempDenom=denominator;
	
	//Increment
	numerator++;
	//Simplify
	Simplify(tempNum, tempDenom);
	
	return *this;	
}

//Rational Object to Double
Rational::operator double()
{
	double convert;

	//Cast the fraction as a double
	convert=(double)numerator/(double)denominator;
	
	return convert;
}

//Insertion and Extraction Operators

//Friends
ostream &operator << (ostream &strm, Rational &obj) 
{
	//Establish << as Cout function
	obj.Cout(strm) ;
	
	return strm ;
}
void Rational::Cout(ostream &out)
{
	//Check for 1 in denom
	if(denominator!=1)
	{
		out << numerator << "/" << denominator << endl;
	}
	else
	{
		out << numerator << endl;
	}	
}

istream &operator>> (istream &strm, Rational &obj)
{
	//Create temps
	int &tempNum=obj.numerator;
	int &tempDenom=obj.denominator;

	//Get cin inputs
	cout<<"Please input the Numerator: ";
	strm>>obj.numerator;
	cout<<"Please input the Denominator: ";
	strm>>obj.denominator;

	obj.Simplify (tempNum, tempDenom);
	
	return strm;
}

//Destructor
Rational::~Rational(void)
{
}
