#include<iostream>
using namespace std;

class Personal     //Personal class to store some personal details
{
  protected:
    char name[20];
    int age;
};

class Professional:virtual public Personal   //inheriting class Personal to Professional
{
 protected:
    int pcount;
};

class Academic:virtual public Personal       //inheriting class Personal to Academic
{
  protected:
    float sgpa;
};

class Biodata: public Professional , public Academic   //inheriting class Professional  and Academic to Biodata
{
    public:
       void accept()              //accept function to take input of the employee
       {
           cout<<"Enter name: ";
           cin>>name;
           cout<<"Enter age: ";
           cin>>age;
           cout<<"how many projects have you done till now? : ";
           cin>>pcount;
           cout<<"Enter your BE SGPA: ";
           cin>>sgpa;
       }

       void display()         //display function details of employee
       {
           cout<<"Name: "<<name<<endl;
           cout<<"Age: "<<age<<endl;
           cout<<"Projects: "<<pcount<<endl;
           cout<<"SGPA: "<<sgpa<<endl<<endl;
       }
};

int main()
{
    Biodata ob[100];
    int ch,i=0;
    do
    {
        cout<<"\n(1) To enter bio-data of employee\n";
        cout<<"(2) To display bio-data of employee\n";
        cout<<"(3) To exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            ob[i++].accept();
            break;
        case 2:
            cout<<"\nDetails of employee\n";
            for(unsigned int j=0;j<i;j++)
            ob[j].display();
            break;
        case 3:
            break;
        default:
            cout<<"Wrong choice\n";
        }
    } while(ch!=3);
    return 0;
}
