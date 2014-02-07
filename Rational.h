#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

class Rational
{
	int numerator;
	int denominator;
	string inWords;
	
	void Simplify(int &num, int &denom) 
	{ 
		int gcd=ComputeGCD(num,denom); 
		num=num/gcd; denom=denom/gcd; 
	}
	int ComputeGCD(int num, int denom) 
	{
		int remainder= denom % num; 
		
		while (remainder != 0) 
		{ 
			denom = num; 
			num = remainder; 
			remainder= denom % num; 
		} return num; 
	} 
		
	public:
		//Constructors
		Rational(void);
		Rational(int);
		Rational(int, int);
		Rational (string W);

		//Copy Constructor
		Rational(const Rational &);
		
		//Assignment Operators
		Rational& operator= (const Rational& other);
		Rational& operator= (const int N);
		Rational& operator= (const string W);
		
		//Addition Operators
		Rational operator+(const Rational &obj);
		Rational operator+(int N);
		Rational operator+(string W);

		//Compound Assignment Operators
		Rational& operator+= (const Rational &obj);
		Rational& operator+=(int num);
		Rational& operator+=(string W);

		//Conditional Operators
		bool operator==(const Rational &obj);
		bool operator>(const Rational &obj);
		
		//Increment Operators
		Rational operator++();
		Rational operator++(int);

		//Convert Object to Double
		operator double();

		//Insertion and Extraction
		void Cout (ostream & out);
		friend ostream &operator<<(ostream &strm, Rational &obj);
		friend istream &operator >> (istream &strm, Rational &obj);

		//Destructor
		~Rational(void);
};

//Outside Overloaded Functions
ostream &operator<<(ostream &strm, Rational &obj);
istream &operator>>(istream &strm, Rational &obj);
#endif

