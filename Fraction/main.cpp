//Author : Soham Ghormade
//Date   : November 7 ,2014

#include<iostream>
#include"Fractions.h"

using namespace std;

int main()
{
	bool result = false;//stores result of comparision operations
	int a = 0,b = 0 ;
	Fraction f1 , f2 , f3 , f4 , f; 

	cout<<"Creating three fractions : "<<endl;
	a = 1 ; b = 4 ;
	f1 = Fraction(a , b );
	cout<<" f1 = "<<f1<<endl;

	a  = -5; b = 6 ;
	f2 = Fraction( a , b );	
	cout<<" f2 = "<<f2<<endl;

	cout<<" Creating  zero denominator fraction ..."<<endl;
	a  = 4; b = 0 ;
	f3 = Fraction( a , b );
	cout<<" f3 = "<<f3<<endl;

	cout<<endl;
	cout<<"Case I :Both operands are fractions:"<<endl;
	f = f1 + f2;
	cout<<" Addition : f1 + f2 = "<<f<<endl;

	f = f1 - f2;
	cout<<" Subtraction : f1 - f2 = "<<f<<endl;

	f = f1 * f2;
	cout<<" Multiplication : f1 * f2 = "<<f<<endl;

	f = f1 / f2;
	cout<<" Division : f1 / f2 = "<<f<<endl;

	cout<<"Case II :Operand I -integer Operand II - fraction :"<<endl;
	cout<<endl;

	f = 12 + f1;
	cout<<" 12 + f1 = "<<f<<endl;

	f = 12 - f1;
	cout<<" 12 - f1 = "<<f<<endl;


	f = 12 * f1;
	cout<<" 12 * f1 = "<<f<<endl;

	f = 12 / f1;
	cout<<" 12 / f1 = "<<f<<endl;

	cout<<"Case III :Operand I -fraction Operand II - integer :"<<endl;
	cout<<endl;
	f = f1 + 12 ;
	cout<<" f1 + 12 = "<<f<<endl;

	f =  f1 - 12;
	cout<<" f1 - 12 = "<<f<<endl;


	f = f1 * 12;
	cout<<" f1 * 12 = "<<f<<endl;

	f = f1 / 12 ;
	cout<<" f1 / 12 = "<<f<<endl;

	cout<<"Case IV :Comparing two fractions"<<endl;

	if( f1 == f2 )
		result = true;
	cout<<" Is f1 == f2 ? "<<boolalpha<<"	  "<<result<<endl;
	cout<<endl;

	result = f1 > f2 ;
	cout<<" Is f1 > f2 ? "<<boolalpha<<"	   "<<result<<endl;
	cout<<endl;

	result = f1 < f2 ; 
	cout<<" Is f1 < f2 ? "<<boolalpha<<"	   "<<result<<endl;
	cout<<endl;

	cout<<"Case V : Comparing a fraction and an integer"<<endl;
	if( f1 == 6 )
		result = true;
	cout<<" Is f1 == 6 ? "<<boolalpha<<"  "<<result<<endl;
	cout<<endl;

	result = f1 > 6 ;
	cout<<" Is f1 > 6 ? "<<boolalpha<<"   "<<result<<endl;
	cout<<endl;

	result = f1 < 6 ; 
	cout<<" Is f1 < 6 ? "<<boolalpha<<"   "<<result<<endl;
	cout<<endl;

	cout<<"Case VI Comparing an integer and a fraction"<<endl;
	if( 6 == f2 )
		result = true;
	cout<<" Is 6 == f2 ? "<<boolalpha<<"  "<<result<<endl;
	cout<<endl;

	result =  6 > f2;
	cout<<" Is 6 > f2 ? "<<boolalpha<<"   "<<result<<endl;
	cout<<endl;

	result = 6 < f2 ; 
	cout<<" Is 6 < f2 ? "<<boolalpha<<"   "<<result<<endl;
	cout<<endl;
	char ch;
	cout<<"Type any key and press enter to exit..";
	cin>>ch;
	return 0;
}
