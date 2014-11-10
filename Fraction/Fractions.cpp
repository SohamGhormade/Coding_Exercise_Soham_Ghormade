//Fractions.cpp 
//class member-function definition

#include <cmath>
#include "Fractions.h"


//Default Constructor
Fraction::Fraction()
{
	f[0] = 0 ;
	f[1] = 1 ;//denominator cannot be zero
}

Fraction::Fraction( array<int,2> _f)
{
	setFraction( _f[0] , _f[1] );
}

Fraction::Fraction( int numerator , int denominator ) 
{
	setFraction(numerator,denominator);
}
//Destructor
Fraction::~Fraction()
		 {}

void Fraction:: setFraction( int numerator , int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
}
void Fraction::setNumerator( int numerator )
{
	f[0] = numerator  ;
}
//Validation for the denominator:
//check whether denominator is non-zero
// Make sure that denominator is  positive i.e numerator /denominator =  +/+ -/+
//if not ,then swap the signs i.e. for cases -/- and +/-
void Fraction::setDenominator( int denominator )
{
	if( denominator != 0 )
	{
	   if(denominator < 0 && getNumerator() < 0 || denominator < 0 && getNumerator() > 0)
	  {
		denominator = -denominator;
		setNumerator( -getNumerator());
	   }
	   f[1] = denominator ;
	}
	else 
		{
			cout<<"Error:denominator cannot be zero  "<<endl;
		    cout<<"Setting denominator to 1"<<endl;
	        f[1] = 1;
	     }
}

int  Fraction::getNumerator() const
{
   return f[0];
}

int  Fraction::getDenominator() const
{
   return f[1];
}
//Addition of two fractions
Fraction Fraction :: operator+(  Fraction& arg)
{ 
   Fraction sum;
   sum.setNumerator( getNumerator() * arg.getDenominator() + getDenominator() * arg.getNumerator());
   sum.setDenominator( getDenominator() * arg.getDenominator());
   sum = sum.simplify();//reduce the fraction
   return sum;
}
//Addition of fraction with an integer
Fraction Fraction:: operator+( int arg )
{
	Fraction sum;
   sum. setNumerator(getNumerator() +  arg * getDenominator());
   sum.setDenominator(getDenominator());
   sum = sum.simplify();
   return sum;

}
//Addition of integer with a fraction
Fraction operator+( int integer, Fraction& fraction )
{
	Fraction sum;
   sum.setNumerator ( integer * fraction.getDenominator() + fraction.getNumerator()) ;
   sum.setDenominator ( fraction.getDenominator() );
   sum = sum.simplify();
   return sum;
}

Fraction Fraction:: operator-(  Fraction& arg)
{ 
   Fraction diff;
   diff.setNumerator( getNumerator() * arg.getDenominator() - getDenominator() * arg.getNumerator() );
   diff.setDenominator( getDenominator() * arg.getDenominator() );
   diff = diff.simplify();
   return diff;
}

Fraction Fraction:: operator-( int arg )
{
	Fraction diff;
	diff.setNumerator( getNumerator() -  arg * getDenominator() ) ;
	diff.setDenominator( getDenominator() );
	diff = diff.simplify();
   return diff;

}

Fraction Fraction::operator-()
{
	Fraction result;
	result.setNumerator( - getNumerator() );
	result.setDenominator( - getDenominator() );
	return result;
}

Fraction operator-( int integer, Fraction& fraction )
{ 
	Fraction diff;
	diff.setNumerator( integer * fraction.getDenominator() - fraction.getNumerator() ) ;
    diff.setDenominator( fraction.getDenominator() );
    diff = diff.simplify();
    return diff;
}

Fraction Fraction:: operator*( Fraction& arg )
{ 
	Fraction mult;
	mult.setNumerator( getNumerator() * arg.getNumerator());
	mult.setDenominator( getDenominator() * arg.getDenominator());
	mult = mult.simplify();
	return mult;
}

Fraction Fraction:: operator*( int arg )
{
	Fraction mult;
	mult.setNumerator(  arg * getNumerator() ) ;
	mult.setDenominator( getDenominator() );
	mult = mult.simplify();
	return mult;

}
Fraction operator*( int integer, Fraction& fraction )
{ 
    Fraction mult;
    mult.setNumerator( integer * fraction.getNumerator() );
    mult.setDenominator( fraction.getDenominator() );
    mult = mult.simplify();
    return mult;
}

Fraction Fraction:: operator/(  Fraction& arg)
{ 
   Fraction div;
   div.setNumerator( getNumerator() * arg.getDenominator() );
   div.setDenominator( getDenominator() * arg.getNumerator() );
   div = div.simplify();
   return div;
}

Fraction Fraction:: operator/( int arg )
{
	Fraction div;
	div.setNumerator(getNumerator());
    div.setDenominator( arg * getDenominator() ) ;
    div = div.simplify();
    return div;

}

Fraction operator/( int integer, Fraction& fraction )
{ 
   Fraction div;
   div.setNumerator( integer * fraction.getDenominator() );
   div.setDenominator( fraction.getNumerator() ) ;
   div = div.simplify();
   return div;
}

bool Fraction::operator==(Fraction &arg)
{ 
	bool result=false,isNumeratorEqual=false,isDenominatorEqual=false;
	simplify();
	arg.simplify();
	 if(getNumerator() == arg.getNumerator())
		 isNumeratorEqual = true;

	 if(getDenominator() == arg.getDenominator())
		 isDenominatorEqual = true;

	 if(isDenominatorEqual & isNumeratorEqual)
			result = true;
	return result;
}

bool Fraction::operator>(Fraction& arg)
{
	bool result = false;
	double d1 = 0,d2 = 0;
	d1 = double(getNumerator()) / getDenominator();
	d2 = double(arg.getNumerator()) / arg.getDenominator();
	
	if( d1 > d2 )
		result = true;
	return result;
}

bool Fraction::operator<(Fraction & arg)
{
	bool result = false;
	double d1 = 0, d2 = 0;
	d1 = double(getNumerator()) / getDenominator();
	d2 = double(arg.getNumerator())/ arg.getDenominator();
	
	if( d1 < d2 )
		result = true;
	return result;
}

bool Fraction::operator==( int  arg )
{
	bool result = false;
	double  d = 0;
	d = double( getNumerator() ) / getDenominator();
	
	if( d == double( arg ) )
		result = true;
	return result;
}

bool Fraction::operator> (  int  arg )
{
	bool result = false;
	double  d = 0;
	d = double( getNumerator() ) / getDenominator();
	
	if( d > double( arg ) )
		result = true;
	return result;
}

bool Fraction::operator< (  int arg ) 
{
	bool result = false;
	double  d = 0;
	d = double( getNumerator() ) / getDenominator();
	
	if( d < double( arg ) )
		result = true;
	return result;
}

bool operator==( int i, Fraction& arg )
{
	bool result = false;
	double  d = 0;
	d = double( arg.getNumerator() ) / arg.getDenominator();
	
	if( double( i ) == d )
		result = true;
	return result;
}
   
bool operator>( int i, Fraction & arg )
{
	bool result = false;
	double  d = 0;
	d = double( arg.getNumerator() ) / arg.getDenominator();
	
	if( double( i ) > d  )
		result = true;
	return result;
}

bool operator<( int i, Fraction& arg )
{
	bool result = false;
	double  d = 0;
	d = double( arg.getNumerator() ) / arg.getDenominator();
	
	if( double( i ) < d )
		result = true;
	return result;
}

istream &operator>>(istream &input, Fraction & arg)
{
	int num = 0 ,den = 0;
	input>>num>>den;
	arg.setFraction(num,den);
	return input;
}

ostream &operator<<(ostream &output, const Fraction & arg)		   
{	
	if(arg.getDenominator()== 1)
		output << arg.getNumerator()<<endl ;
	else
		output << arg.getNumerator() << " / " << arg.getDenominator()<<endl ; 
	return output;
}

int computeGCD(int a, int b)
{
	//if b is greater than a, then swap them without using additional memory
  if (a < b)
  {
    a += b;
    b = a - b;
    a -= b;
  }
      if (b == 0)
    return a;  
  
  while ( a % b != 0 )
  {
    a += b;
    b = a - b;
    a -= b;
    b %= a;
  }
  return b;
}


Fraction Fraction :: simplify()
{
  Fraction result;
  int gcd = 0;
  gcd = computeGCD( abs(f[0]) , abs(f[1]) );
	if( gcd != 0 )
	{ 
		result.f[0] = f[0] / gcd;
	    result.f[1] = f[1] / gcd;
	}
 return result;
}
