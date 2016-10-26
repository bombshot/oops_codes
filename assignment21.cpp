#include<bits/stdc++.h>
using namespace std;

class Queue
{
	list< int > l;
	list<int> ::iterator it;
	public:
	void dequeue();
	void enqueue(int );
	void print();
};

void Queue::enqueue(int a)
{
	l.push_back(a);
}

void Queue::dequeue()
{
	it=l.begin();

	if(it==l.end())
	cout<<"\nNO element in the queue : ";
	else
	{
		l.pop_front();
		cout<<"\nelement deleted : \n";	
	}
}	

void Queue::print()
{
	it=l.begin();
	 
	if(it==l.end())
	cout<<"\nNo elements in the queue : ";

	else 
	cout<<"Queue elements are : ";

	for(it=l.begin();it!=l.end();it++)
	cout<<*it<<" ";
	cout<<"\n";

}

int main()
{

	Queue q;

	int choice,x;
	char ch;

	do
	{
		cout<<"\nEnter 1 for enqueue : \nEnter 2 for dequeue : \nEnter 3 for print : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"Enter the value you want to enter : ";
				cin>>x;
				q.enqueue(x);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.print();
				break;
			default:
			cout<<"\nInvalid choice : ";
		}
	cout<<"\nDo you want to continue : ";
	cin>>ch;

	}
	while(ch=='y'||ch=='Y');


return 0;

}

