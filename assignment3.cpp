
#include<bits/stdc++.h>
using namespace std;

class Polynomial
{

	float a[3];

	public:
	
	Polynomial()
	{
		for(int i=0;i<3;i++)
			a[i]=0;	
	
	}	

	Polynomial(float x,float y,float z)
	{
		a[0]=z;
		a[1]=y;
		a[2]=x;
	}
	
	friend istream& operator>>(istream &,Polynomial &);
	friend ostream& operator<<(ostream &,Polynomial &);

	Polynomial operator+(Polynomial c);
	Polynomial operator-(Polynomial c);

	float eval(float );
	void sol();
	

};


float Polynomial::eval(float x)
{

	float ans=0;
	
	for(int i=0;i<3;i++)
	ans+=a[i]*pow(x,i);

	return ans;
}

void Polynomial::sol()
{
	float temp,ans,a1,b1;
	
	temp=a[1]*a[1]-4*a[2]*a[0];

	if(a[2]==0)
	{

		if(a[1]==0)
		ans=0;
		else
		ans=(-a[0])/a[1];

		cout<<"Solution of this Polynomial is "<<ans;
		return ;


	}

	if(temp<0)
	{
		cout<<"Imaginary Solution of this Polynomial ";
		return ;

	}
	

	temp=sqrt(temp);


	a1=((-a[1])+temp)/(2*a[2]);
	b1=((-a[1])-temp)/(2*a[2]);

	cout<<"Solution of this Polynomial is "<<a1;
	if(a1!=b1)
	cout<<" and "<<b1;

}

Polynomial Polynomial::operator-(Polynomial p)
{
	Polynomial p2;
	
	for(int i=0;i<3;i++)
	p2.a[i]=a[i]-p.a[i];

	return p2;

}




Polynomial Polynomial::operator+(Polynomial p )
{
	Polynomial p2;
	
	for(int i=0;i<3;i++)
	p2.a[i]=a[i]+p.a[i];

	return p2;

}


istream& operator>>(istream & cin, Polynomial & p)
{
	float a,b,c;	

	cout<<"enter the coeffecient of x2 , x and constant term : ";
	cin>>a>>b>>c;

	p=Polynomial(a,b,c);

	return cin;

}






ostream& operator<<(ostream & cout,Polynomial & p)
{


	cout<<p.a[2]<<" x^2 ";
	
	if(p.a[1]<0)	
	cout<<" "<<p.a[1]<<" x ";
	
	else 
	cout<<" + "<<p.a[1]<<" x ";

	if(p.a[0]>=0)
	cout<<"+ "<<p.a[0];

	else
	cout<<" "<<p.a[0];
	
	
	return cout;

}


int main()
{
	
	Polynomial p,p2,add,sub;
	char ch,ch2;
	
	float evaluate,x;
	
	do
	{
		cin>>p>>p2;

		do
		{		


		cout<<"\n\n"<<"Enter 1 for Addition   \nEnter 2 for Substraction   \nEnter 3 for Evaluation \nEnter 4 for solving the polynomial 				"<<"\n\n";
		int no;
	
		cin>>no;
	
		
		switch(no)	
		{
			case 1:
			{	
				add=p+p2;
				
				cout<<"\n*********************************************\n";				

				cout<<"Polynomial addition is = "<<add<<"\n\n";
				

				cout<<"\n*********************************************\n";
				break;
			}

			case 2:
			{
				sub=p-p2;
				
				cout<<"\n*********************************************\n";				

				cout<<"Polynomial Substraction is = "<<sub<<"\n\n";
				

				cout<<"\n*********************************************\n";
				break;				

			}

			case 3:

			{

				int n;
				float temp;
				cout<<"\n\nEnter 1 for Evaluation of Polynomial 1\nEnter 2 for evaluation of Polynomial 2 ";
				cin>>n; 
				
				cout<<"\nEnter the value of x for which you want evaluate the polynomial : ";

				cin>>temp;
				
				cout<<"\n*********************************************\n";	

				if(n==1)
				evaluate=p.eval(temp);

				else if(n==2)
				evaluate=p2.eval(temp);
				
				else
				{
					cout<<"Invalid Input";
					cout<<"\n*********************************************\n";			
						
					break;
				}

				cout<<"On evaluating the Polynomial we get solution : "<<evaluate<<endl<<endl;
				cout<<"\n*********************************************\n";	

				break;
			
			
			}	

			case 4:
				{
					int n;
					cout<<"\n\nEnter 1 for Solution of Polynomial 1\nEnter 2 for Solution of Polynomial 2  ";
				cin>>n; 
				
				cout<<"\n*********************************************\n";	
				
				if(n!=1&&n!=2)
				{
					cout<<"Invalid Input";
					
					break;
				}

				else if(n==1)
				p.sol();

				else 
				p2.sol();
				
				
				cout<<"\n*********************************************\n";	

				break;
			
					

				}

			default:
			cout<<"Invalid input"<<"\n\n";
		}

		cout<<"\n\nWant more operations on these Polynomials (y/n) : ";
		cin>>ch2;
		}
		while(ch2=='y'||ch2=='Y');
	

	cout<<"\n\nWant more operation (y/n): ";
	cin>>ch;
	}
	while(ch=='y'||ch=='Y');

	

return 0;
}

