#include<bits/stdc++.h>
using namespace std;

class student
{
    int roll;
    string name;
    float marks;
public:
    student()
    {
        roll=0;
        name="";
        marks=0.0;
    }
    void wfile();
    void rfile();

};
void student::wfile()
{
    ofstream ob1;
    ob1.open("Students.txt",ios::app);
    cout<<"\nEnter Roll no. : ";
    cin>>roll;
    ob1<<roll<<"\n";
    cout<<"\nEnter Name : ";
    cin>>name;
    ob1<<name<<"\n";
    cout<<"\nEnter Marks : ";
    cin>>marks;
    ob1<<marks<<endl;
}
void student::rfile()
{
    ifstream ob2;
    ob2.open("Students.txt",ios::in);
    cout<<"\nEntered database:";

	while(!ob2.eof())
    {
        cout<<"\nRoll No.: ";
        ob2>>roll;
        cout<<"\nName : ";
        ob2>>name;
        cout<<"\nMarks : ";
        ob2>>marks;
        if(ob2.eof()){
            break;
        }
        cout<<roll;
        cout<<name;
        cout<<marks;

    }

}


int main()
{
    char flag;

    student s;
    cout<<"Enter Database: ";

	do{
        s.wfile();
        cout<<"Do you want to add another dataset (y/n): ";
        cin>>flag;
    }while(flag=='y'||flag=='y');

    s.rfile();
    return 0;
}
