#include<iostream>
#include<math.h>
using namespace std;


int main()
{

	
	

	int i=0,temp,count,nn1=0,nn2=0;
	float n1=0,n2=0,n3=0,n4=0,ans;
	char s[10],ch;
	cin>>s;

	
	
	if(s[0]=='-')
	{
		i++;
		nn1=1;                          					//if number 1 is negative
	}
	while(1)
	{

		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{						
			temp=i;								//for the position of the operator

			break;
		}

		if(s[i]=='.')
		{
			count=1;
			i+=1;								//if dot found calculate the fraction part

			while(1)
			{

				if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
				{
				temp=i;

				break;
				}
    	
			n2=n2+(s[i]-48)/pow(10,count);
			i++;
			count++;
			}

			break;
		}

		
		{	
			n1=n1*10+(s[i]-48);

			i++;

		}
	}



	i=temp+1;
	if(s[i]=='-')
	{
		i++;
		nn2=1;									//if number 2 is negative
	}


	while(s[i]!='\0')
	{
		if(s[i]=='.')								//if dot found calculate the fraction part
		{
			
			count=1;
			i++;

			while(s[i]!='\0')
			{
				n4=n4+(s[i]-48)/pow(10,count);
				i++;
				count++;
			}
				break;

		}
		


		n3=n3*10+(s[i]-48);
		i++;

	}



	
	n1+=n2;										//addition of the decimal part to the number 1
	n3+=n4;										//addition of the decimal part to the number 2

	if(nn1==1)
	n1=-n1;										//making number 1 negative

	if(nn2==1)
	n3=-n3;										//making number 2 negative

	switch(s[temp])
	{

		case '+':
		ans=n1+n3;
		break;

		case '-':
		ans=n1-n3;
		break;

		case '*':
		ans=n1*n3;
		break;

		case '/':
		ans=n1/n3;
		break;


	}	

	cout<<"ans="<<ans<<endl;
	cout<<"want more operation (y/n) ";
	cin>>ch;									//for more operations


      if(ch=='y'||ch=='Y')
	main();
	
	return 0;
}

