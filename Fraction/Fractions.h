// Fractions.h
// Fraction class  definition 
#ifndef FRACTIONS_H
#define FRACTIONS_H
#include <iostream>
#include <array>

using namespace std;

class Fraction// numerator / denominator ; where denominator!= 0
{
private: 
	    array<int,2> f;// numerator = a [ 0 ], denominator = a [ 1 ]
		
public:
	Fraction();
	Fraction(array<int,2>);
	Fraction( int , int  );
	~Fraction();
	
	Fraction simplify();

	
	void setFraction(int  , int );
	void setNumerator(int );
	void setDenominator( int );
	
	int  getNumerator() const;
	int  getDenominator() const;

	Fraction operator+( Fraction&);
	Fraction operator+( int );
	friend Fraction operator+( int, Fraction& );

	Fraction operator-( Fraction&);
	Fraction operator-( int );
	friend Fraction operator-( int, Fraction& );

	Fraction operator-();
	
	Fraction operator*( Fraction&);
	Fraction operator*( int );
	friend Fraction operator*( int, Fraction& );

	Fraction operator/( Fraction&);
	Fraction operator/( int );
	friend Fraction operator/( int, Fraction& );


	bool operator==(Fraction&);
	bool operator>(Fraction&);
	bool operator<(Fraction&);

	bool operator==( int  );
	bool operator> (  int );
	bool operator< (  int ) ;

	friend bool operator==( int, Fraction& );
	friend bool operator>( int, Fraction& );
	friend bool operator<( int, Fraction& );

	friend istream &operator>>(istream &, Fraction &);
	friend ostream &operator<<(ostream &, const Fraction &);

		
};
#endif