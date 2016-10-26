#include<bits/stdc++.h>
using namespace std;

class publisher
{
	protected:
	char title[100];
	float price;
	public:
	virtual void display(){};
	publisher(char* s="NO TITLE",float p=0)
	{
		strcpy(title,s);
		price=p;
	}

	virtual void getdata(char *);
};

void publisher::getdata(char *s)
{

	cout<<"\nenter the title of the "<<s<<" : ";
	cin>>title;

	cout<<"\nEnter the price of the "<<s<<" : ";
	cin>>price;

}

class book:public publisher
{
	int page;

	public:
	void display();
	void getdata();
	book(char *s="NO TITLE",float price=0.0,int p=0):publisher(s,price)
	{
		page=p;
	}

};


class tape:public publisher
{

	float time;
	public:
	void display();
	void getdata();
	tape(char * s="NO TITLE",float price=0.0,float t=0.0):publisher(s,price)
	{
		time=t;
	}

};

void book::getdata()
{
	float p;
	publisher::getdata("book");
	cout<<"\nEnter the pages in the book : ";
	cin>>p;
	page=p;
	try
	{
		if(price<=0||page<=0||p!=page)
		{
			throw title;

		}

	}

	catch(...)
	{
		strcpy(title,"NO TITLE");
		price=0;
		page=0;
	}
}


void tape::getdata()
{
	publisher::getdata("tape");

	cout<<"\nEnter the playing time of the tape : ";
	cin>>time;

	try
	{
		if(price<=0||time<=0)
		{
			throw title;

		}

	}

	catch(...)
	{
		strcpy(title,"NO TITLE");
		price=0;
		time=0;
	}

}

void book::display()
{
	cout<<"\n\nTitle of the book is : "<<title;
	cout<<"\n\nPrice of the book is : "<<price;
	cout<<"\n\nPages in the book is : "<<page;

}


void tape::display()
{
	cout<<"\n\nTitle of the tape is : "<<title;
	cout<<"\n\nPrice of the tape is : "<<price;
	cout<<"\n\nPlaying time of the tape in minutes  is : "<<time;

}

int main()
{

	book b[100];
	tape t[100];

	int ch,bcnt=0,tcnt=0;
	char choice;

	do
	{

	cout<<"\n\nEnter 1 for enter data of book \n\nEnter 2 for enter data of the tape \n\nEnter 3 for Display the data of book \n\nEnter 4 for display of the tape : ";

	cin>>ch;

	switch(ch)
	{
		case 1:
		b[bcnt++].getdata();
		break;

		case 2:
		t[tcnt++].getdata();
		break;

		case 3:
		for(int i=0;i<bcnt;i++)
		{
			cout<<"\n\n**********  book"<<i+1<<" is ************************: \n\n";
			b[i].display();

		}
		break;

		case 4:
		for(int i=0;i<tcnt;i++)
		{
			cout<<"\n\n**********  tape"<<i+1<<" is ************************: \n\n";
			t[i].display();

		}
		break;

		default:
		cout<<"\nInvalid Input : \n";

	}

	cout<<"\n\nWants more operations : ";
	cin>>choice;

	}
	while(choice=='y'||choice=='Y');

return 0;
}
