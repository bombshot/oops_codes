#include<bits/stdc++.h>
using namespace std;

int main()
{
    fstream ob1;
    string s,s1;
    char ch,c;
    int z=0,w=0;

	do
    {
        cout<<"\n1 for adding new contact\n2 for determining the telephone number of specified person \n3 for Determining name if telephone number is know \n4 Update telephone number of person";
        cout<<"\n5 for exit\n\nenter your choice:";
        cin>>ch;
        switch(ch)
        {
        case '1':
            {
                ob1.open("telephone.txt",ios::out|ios::app);
                cout<<"enter name of person: ";
                cin>>s;
                ob1<<s;
                ob1<<" ";
                cout<<"enter his/her phone number: ";
                cin>>s1;
                ob1<<s1;
                ob1<<"\n";
                ob1.close();
                break;
            }
        case '2':
            {
                cout<<"enter name of person whose number u want to know : ";
                cin>>s;
                ob1.open("telephone.txt",ios::in);
                while(!ob1.eof())
                {
                  ob1>>s1;
                  if(s1==s)
                  {
                      ob1>>s1;
                      cout<<"phone number of "<<s<<" is "<<s1;
                      z=1;
                      break;
                  }
                  ob1>>s1;
                }
                if(z==0)
                cout<<"\nPerson not found in Record \n";
                z=0;
                ob1.close();
                break;
            }
        case '3':
            {
                cout<<"enter mobile number of person whose name u want to know: ";
                cin>>s;
                string s2;
                ob1.open("telephone.txt",ios::in);
                while(!ob1.eof())
                {
                    ob1>>s1;
                    ob1>>s2;
                    if(s2==s)
                    {
                        cout<<"number u enter "<<s<<" is register with name "<<s1;
                        w=1;
                        break;
                    }
                }
                if(w==0)
                    cout<<"sorry no such number is in our file\n";
                    w=0;
                    ob1.close();
                    break;
            }
        case '4':
            {
                ob1.open("telephone.txt",ios::out|ios::in);
                cout<<"enter name of person whose number is to be updated : ";
                cin>>s;
                string s3,s2;
                cout<<"enter new number : ";
                cin>>s3;
                while(!ob1.eof())
                {
                    ob1>>s2;
                    ob1>>s1;
                    if(s2==s)
                    {
                        ob1.seekg(-11,ios::cur);
                        ob1<<s3;
                        z=1;
                        ob1.close();
                        break;
                    }
                }
                if(z==0)
                cout<<"sorry no such person have file record\n";
                z=0;
                ob1.close();
                break;
            }

        case '5':
            	return 0;
            	break;
        default:
            {
                cout<<"\nInvalid Input : \n\n";

            }
        }
        cout<<"\ndo u want to continue (y/n):";
        cin>>c;
    }while(c=='y'||c=='Y');
}
