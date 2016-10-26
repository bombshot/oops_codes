/*
-----------------------------------------------------------------------------------------------------------------
=   Write C++ Program with base class convert declares two variables, val1 and val2, which			=
=   hold the initial and converted values, respectively. It also defines the functions getinit( ) and		=
=   getconv( ), which return the initved ial value and the converted value. These elements of convert		=
=   are fixed and applicable to all dericlasses that will inherit convert. However, the function		=
=   that will actually perform the conversion, compute( ), is a pure virtual function that must be		=
=   defined by the classes derived from convert. The specific nature of compute( ) will be			=
=   determined by what type of conversion is taking place.							=
=														=
-----------------------------------------------------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Convert
{
	protected:
	float v,v2;

	public:
	Convert()
	{
		v=0;
		v2=0;
	}
	float getinit();
	float getconv();
	void getdata();
	virtual void conv()=0;
};

void Convert::getdata()
{
	cout<<"\nEnter the no : ";
	cin>>v;
	conv();
}


float Convert::getinit()
{
	return v;
}


float Convert::getconv()
{
	return v2;
}


class Square:public Convert
{

	public:
	void conv()
	{
		v2=v*v;
	}

};

class Sqrt:public Convert
{
	public:
	void conv()
	{
		v2=sqrt(v);
	}

};

int main()
{
	Square square;
	Sqrt sqrt;

	int choice;
	char ch;


	do
	{


		cout<<"\n********************************************************************\n";
		cout<<"Enter 1 for Conversion into Square of no : \nEnter 2 for Conversion into Square root of no : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
			square.getdata();
			cout<<"\nSquare of "<<square.getinit()<<" is : "<<square.getconv();
			break;

			case 2:
			sqrt.getdata();

			if(sqrt.getinit()>=0)
			cout<<"\nSquare Root of "<<sqrt.getinit()<<" is : "<<sqrt.getconv()<<endl;
			else
			cout<<" Square Root of -ve No cannot be calculated \n";
			break;

			default:
			cout<<"\nInvalid Input\n";

		}
	cout<<"\n********************************************************************\n";
	cout<<"\nWants More Operations (Y/N): ";
	cin>>ch;

	}
	while(ch=='y'||ch=='Y');


return 0;
}
