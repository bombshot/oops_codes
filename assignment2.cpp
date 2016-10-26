/*

implement a class complex which represent the complex no datatype .implement the following operatons
1.constructor including a default constructor which create 0+0i
2.overload operator + 
3.overload operator * 
4.overload insertion and extraction operator to read and output complex no;

*/


#include<iostream>
using namespace std;

class Complex
{

	float real,imag;

	public:
	
	Complex()
	{
		real=0;
		imag=0;
	}	

	Complex(float r,float i)
	{
		real=r;
		imag=i;
	}
	
	friend istream& operator>>(istream &,Complex &);
	friend ostream& operator<<(ostream &,Complex &);

	Complex operator+(Complex c);
	Complex operator*(Complex c);
	Complex operator-(Complex c);
	
	
};

Complex Complex::operator-(Complex c)
{
	Complex c2;
	
	c2.real=real-c.real;
	c2.imag=imag-c.imag;

	return c2;

}


Complex Complex::operator*(Complex c)
{
	Complex c2;
	
	c2.real=real*c.real-imag*c.imag;
	c2.imag=real*c.imag+c.real*imag;

	return c2;

}

Complex Complex::operator+(Complex c)
{
	Complex c2;
	
	c2.real=real+c.real;
	c2.imag=imag+c.imag;

	return c2;

}


istream& operator>>(istream & cin, Complex & c)
{
	float real,imag;	

	cout<<"enter the real and imag part of complex no : ";
	cin>>real;
	cin>>imag;

	c=Complex(real,imag);

	return cin;

}






ostream& operator<<(ostream & cout,Complex & c)
{

	cout<<c.real;
	
	if(c.imag>=0)	
	cout<<" + "<<c.imag<<"i"<<endl<<"\n";
	
	else
	cout<<c.imag<<"i"<<endl<<"\n";

	
	
	return cout;

}


int main()
{
	
	Complex c1,c2,c3,c4,c5;
	char ch;
	
	do
	{
		cin>>c1>>c2;

		cout<<"\n\n"<<"Enter 1 for Addition   \nEnter 2 for Substraction   \nEnter 3 for Multiplication "<<"\n\n";
		int no;
	
		cin>>no;

		switch(no)	
		{
			case 1:
			{	
				c3=c1+c2;
				
				cout<<"\n*********************************************\n";				

				cout<<"complex no addition is = "<<c3<<"\n";
				

				cout<<"\n*********************************************\n";
				break;
			}

			case 2:
			{
				c5=c1-c2;
				
				cout<<"\n*********************************************\n";

				cout<<"substraction of complex no is = "<<c5<<"\n";
					
				
				cout<<"\n*********************************************\n";
				break;
			}

			case 3:

			{

				
				cout<<"\n*********************************************\n";

				c4=c1*c2;
				cout<<"complex no multiplication is ="<<c4<<"\n";
				
				cout<<"\n*********************************************\n";
				break;
			
			
			}	

		

			default:
			cout<<"Invalid input"<<"\n\n";
		}
	
	cout<<"Want more operation (y/n):";
	cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	

return 0;
}

