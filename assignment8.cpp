/*

Create a class Rational Number (fractions) with the following capabilities:
a) Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
b) Overload the addition, subtraction, multiplication and division operators for this class.
c) Overload the relational and equality operators for this class.

*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
	return a;
	
	return gcd(b,a%b);
}

int lcm(int a,int b)
{
	int ans=(a*b)/gcd(max(a,b),min(a,b));
	return ans;
}

class Rational
{
  int num,den;
  
  public:
  Rational(int ,int );
  Rational(){num=1;den=1;};
  Rational getdata();
  Rational operator+(Rational );
  Rational operator-(Rational );
  Rational operator*(Rational );
  Rational operator/(Rational );
  friend ostream & operator<<(ostream &,Rational );
	
};

ostream & operator<<(ostream & cout,Rational b)
{
	cout<<b.num<<"/"<<b.den;
	return cout;
}

Rational Rational ::operator+(Rational a)
{
	Rational b;
	b.den=lcm(den,a.den);		
	b.num=num*(b.den/den)+a.num*(b.den/a.den);
	b=Rational(b.num,b.den);
	return b;
}

Rational Rational ::operator-(Rational a)
{
	Rational b;
	b.den=lcm(den,a.den);		
	b.num=num*(b.den/den)-a.num*(b.den/a.den);
	b=Rational(b.num,b.den);
	return b;
}

Rational Rational ::operator*(Rational a)
{	
	Rational b;
	b.num=num*a.num;
	b.den=den*a.den;
	b=Rational(b.num,b.den);
	return b;
}


Rational Rational ::operator/(Rational a)
{
	Rational b;
	b.num=num*a.den;
	b.den=den*a.num;
	b=Rational(b.num,b.den);
	return b;
}

Rational:: Rational(int a,int b)
  {
  
  	if(b==0)
  	{
  		cout<<"\nInvalid no Please Enter Again \n";
  		getdata();
  	}
  	
  	else 
  	{
  		if(b<0)
  		{
  			a=-a;
  			b=-b;
  		}
  	
  		int x=max(abs(a),abs(b));
  		int y=min(abs(a),abs(b));
  		
  		num=a/gcd(x,y);
  		den=b/gcd(x,y);
	}
	
}
  

Rational Rational::getdata()
{
	Rational r;
	
	cout<<"\nEnter the value of numerator and denominator : ";
	cin>>r.num>>r.den;
	r=Rational(r.num,r.den);
	return r;	
}

int main()
{

	Rational r,r2,add,sub,mul,div;
	cout<<"\n First Rational No \n";
	r=r.getdata();
	cout<<"\n Second Rational No \n";
	r2=r2.getdata();
	
	char c;
	do
	{
		int choice;
		cout<<"Enter 1 for addition : \nEnter 2 for Substraction : \nEnter 3 for multiplication : \nEnter 4 for division : ";
		cout<<"\nEnter 5 for display First Rational NO : \nEnter 6 for display Second Rational NO : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			   add=r+r2;
			   cout<<"\nAddition of "<<r<<" and "<<r2<<" is = "<<add<<"\n";
			   break;
			case 2:
			   sub=r-r2;   
			   cout<<"\nSubstraction of "<<r<<" and "<<r2<<" is = "<<sub<<"\n";
			   break;
			case 3:
			   mul=r*r2;   
			   cout<<"\nMultiplication of "<<r<<" and "<<r2<<" is = "<<mul<<"\n";
			   break;
			case 4:
			   div=r/r2;   
			   cout<<"\nDivision of "<<r<<" and "<<r2<<" is = "<<div<<"\n";
			   break;
			 case 5:
			    cout<<"\nFirst Rational No is = "<<r;
			    break;
			 case 6:
			    cout<<"\nSecond Rational No is = "<<r2;
			    break;  
			default:
			cout<<"\n Enter a Valid choice \n";   
		}
		
		cout<<"\nWants More Operations (y/n) : ";
		cin>>c;
	}
	while(c=='y'||c=='Y');	
	
	return 0;
}
