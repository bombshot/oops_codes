/*c++ program using STL for searching and sorting with user defined records
  Person record(name,birth date,telno),item record(item code,item name,quantity and cost)
*/

#include<bits/stdc++.h>
using namespace std;

struct DOB
   {
	int date,mon,year;
   };

class Person
   {
	string name;
	DOB dob;
	long long telno;
    public:
	Person();
	void input();
	void display();
	friend bool compName(Person,Person);
	friend bool compDob(Person,Person);
	friend bool compTel(Person,Person);
	friend int search(Person[],int,int);
	friend int search(Person[],int,string);
	friend int search(Person[],int,DOB);

   };



Person::Person()
   {
	name="";
	dob.date=dob.mon=dob.year=0;
	telno=0;
   }

void Person::input()
   {
	cout<<"\nEnter name : ";
	cin>>name;
	cout<<"Enter DOB (space separated DD MM YYYY) : ";
	cin>>dob.date>>dob.mon>>dob.year;
	cout<<"Enter telno : ";
	cin>>telno;
   }

void Person::display()
   {
	cout<<"\n\nName : "<<name;
	cout<<"\nDOB  : "<<dob.date<<"/"<<dob.mon<<"/"<<dob.year;
	cout<<"\nTelno: "<<telno;
   }

bool compName(Person p1,Person p2)
   {
	if(p1.name<=p2.name)
	  return true;
	else
	  return false;
   }

bool compDob(Person p1,Person p2)
   {
	if(p1.dob.year<p2.dob.year)
	  return true;
	else if(p1.dob.year>p2.dob.year)
	  return false;
	else
	  {if(p1.dob.mon<p2.dob.mon)
	     return true;
	   else if(p1.dob.mon>p2.dob.mon)
	     return false;
	   else
	     {
		if(p1.dob.date<=p2.dob.date)
	     	  return true;
	        else
	          return false;
	     }
	  }
   }

/*bool compTel(Person p1,Person p2)
   {
	if(p1.telno<=p2.telno)
	  return true;
	else
	  return false;
   }*/

int search(Person per[],int size,int tel)
   {
	for(int i=0;i<size;i++)
	   {if(tel==per[i].telno)
	      {return i;
	       break;
	      }
	   }
	return -1;
   }

int search(Person per[],int size,string nm)
   {
	for(int i=0;i<size;i++)
	   {
	       if(nm==per[i].name)
	      {
	          return i;
	          break;
	      }
	   }
	return -1;
   }

int search(Person per[],int size,DOB db)
   {
	for(int i=0;i<size;i++)
	   {
	       if(db.date==per[i].dob.date && db.mon==per[i].dob.mon && db.year==per[i].dob.year)
	      {
	          return i;
              break;
	      }
	   }
	return -1;
   }

int main()
   {
	Person per[50];
	int cnt=0;
	int ip,index,tel;
	string name;
	DOB dob;
	char choice='y';

	while(choice=='y' || choice=='Y')
	   {
	     cout<<"\n1.Enter a person's record...";
	     cout<<"\n2.Display record...";
	     cout<<"\n3.Sort by name...";
	     //cout<<"\n4.Sort by telno...";
	     cout<<"\n4.Sort by DOB...";
	     cout<<"\n5.Search for telno...";
	     cout<<"\n6.Search for name...";
	     cout<<"\n7.Search for DOB...";
	     cout<<"\n8.Exit...";
	     cout<<"\nEnter your choice(1-8) : ";
	     cin>>ip;

	     switch(ip)
		{
		 case 1:per[cnt++].input();
			break;
		 case 2:for(int i=0;i<cnt;i++)
			   per[i].display();
			break;
		 case 3:sort(per,per+cnt,compName);
			break;
		 //case 4:sort(per,per+cnt,compTel);
			//break;
		 case 4:sort(per,per+cnt,compDob);
			break;
		 case 5:cout<<"\nEnter telno : ";
			cin>>tel;
			index=search(per,cnt,tel);
			if(index==-1)
			  cout<<"\nNot found...";
			else
			  per[index].display();
			break;
		 case 6:cout<<"\nEnter name : ";
			cin>>name;
			index=search(per,cnt,name);
			if(index==-1)
			  cout<<"\nNot found...";
			else
			  per[index].display();
			break;
		case 7:cout<<"\nEnter DOB (space separated DD MM YYYY) : ";
		       cin>>dob.date>>dob.mon>>dob.year;
		       index=search(per,cnt,dob);
			if(index==-1)
			  cout<<"\nNot found...";
			else
			  per[index].display();
			break;
		 case 8:return 0;
		 default:cout<<"\nWrong choice";
	       }
     	  cout<<"\nDo you want to continue(y/n) : ";
          cin>>choice;
         }
         return 0;
   }


