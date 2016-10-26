#include<bits/stdc++.h>
using namespace std;

class check
{
   int age;
   int income;
   string city;
   int four_check;
   public:
       check()
       {
           age=0;
           income=0;
           four_check=0;
       }
       
     	void in();  
       
};


void check:: in()
{
           cout<<"enter the age of a User : ";
           cin>>age;
          
		   cout<<"\nenter his income : ";
           cin>>income;
          
		   cout<<"\nenter city where user live : ";
           cin>>city;
          
		   cout<<"\ndid user has four wheeler\n(1 for YES or 0 for NO) : ";
           cin>>four_check;
          
		   try
           {
               if(age<18 || age>55)
               {
                   throw(1);
               }
               
               if(income<50000 || income >100000)
               {
                   throw(2);
               }
               
               if(city=="Pune"||city=="Mumbai"||city==" Bangalore"||city==" Chennai"||city=="pune"||city=="mumbai"||city=="bangalore"||city=="chennai");
               else
               {
                   throw(3);
               }
               
               if(four_check!=1)
               {
                   throw(4);
               }
               
           }
           
           catch(int c)
           {
               if(c==1)
                cout<<"\n\nage is not as per desire\n";
               if(c==2)
                 cout<<"\n\nincome is not as per desire\n";
               if(c==3)
                 cout<<"\n\nUser is not living in city  Pune/ Mumbai/ Bangalore / Chennai \n";
                if(c==4)
                  cout<<"\n\nuser do not have four wheeler\n";
            return;
           }
           
           cout<<"\n\n Perfect User \n";
	}



 int main()
 {
     check ob1;
     char c;
     
	 do     
	 {
         ob1.in();
         cout<<"\ndo u want to continue:(y/n)";
         cin>>c;
     
	 }
     while(c=='y'||c=='Y');
     
	return 0;
 }
