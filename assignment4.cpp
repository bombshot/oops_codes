#include<bits/stdc++.h>

using namespace std;

class Cpparray
{
	float array[100];
	int n;
	
	public:
	Cpparray()
	{
		for(int i=0;i<100;i++)
		array[i]=0;
		
		n=0;
	
	}
	
	friend istream & operator>>(istream & , Cpparray & );
	friend ostream & operator<<(ostream &, Cpparray  & );
	float& operator[](int p);	
	void operator=(Cpparray& ob);
	void range();
	void length();
};


void Cpparray::length()
{
	cout<<"\nThe size of the Array is : "<<n<<"\n";
}


ostream & operator<<(ostream & cout,Cpparray & ob)
{

	if(ob.n==0)
	{
		cout<<"\n No elements in the Array : \n";
		return cout;
	}
	
	for(int i=0;i<ob.n;i++)
	cout<<ob.array[i]<<"  ";
	
	cout<<endl;
	
	return cout;
}


void Cpparray::operator=(Cpparray &ob)
{
	n=ob.n;
		
	for(int i=0;i<n;i++)
	{
		array[i]=ob.array[i];	
	}
}


void Cpparray::range()
{
	int a,b;
	float min,max;
		
	cout<<"\n\nEnter the index of lower bound and Upper bound for Range check : ";
	cin>>a>>b;
		
	if(a>b)
	{
		cout<<"\nLower index should be greater then Upper index : \n";
		return ;
	}
		
	 else if(a<0||a>n-1||b<0||b>n-1)
	{
		cout<<"\nIndex are out of range of the array\n";
		return ;
	}
	
	min=array[a];
	max=array[b];
	
	for(int i=a+1;i<=b;i++)
	{
		
		if(array[i]<min)
		min=array[i];
			
		if(array[i]>max)
		max=array[i];
		
	}
	
	cout<<"\nMinimum Value in the range is : "<<min<<endl;
	cout<<"\nMaximum Value in the range is : "<<max<<endl;
}


istream & operator>>(istream & cin, Cpparray & ob)
{
	cout<<"\nEnter the no of Elements in the Array : ";
	cin>>ob.n;
	for(int i=0;i<ob.n;i++)	
		
	cin>>ob[i];
}
	
	
float& Cpparray::operator[](int n )
{
	
	return array[n];	
}
	

int main()
{

	Cpparray ob1,ob2;

	
	cin>>ob1;
	
	int choice;
	char ch;
	
	
	do
	{
	
	
	cout<<"\nEnter 1 for Range Checking \nEnter 2 for making ob1=ob2 \nEnter 3 for printing Array 1 \nEnter 4 for Printing Array 2 \nEnter"; 		cout<<" 5 for the no of elements in the array  ";
	
		cin>>choice;
	
	
		switch(choice)
		{
	
			case 1:
			{
		
				ob1.range();
				break;
			}
		
			case 2:
			{
		
				ob2=ob1;
				break;
			}
		
			case 3:
				cout<<ob1;
				break;
		
			case 4:
				cout<<ob2;
				break;
			case 5:
				ob1.length();
				break;
			
			default:
			cout<<"\nInvalid Input :\n\n";	
	
		}
	
		cout<<"\n\nWants More Operations (y/n) : ";
		cin>>ch;
		
	}
	while(ch=='Y'||ch=='y');	
	
		

	return 0;

}
