#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
void create();       //create function to create the file and write data to it
void display();      //display function to display details of products stored in the file
void remov();        //remov function to delete details of a specified product
int main()
{
    int ch;
    do
    {
        cout<<"(1) To enter the record into the file\n";
        cout<<"(2) To display the details of products\n";
        cout<<"(3) To remove the record of a product\n";
        cout<<"(4) To exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                remov();
                break;
            case 4:
                break;
            default:
                cout<<"Wrong choice\n";
                break;
        }
    }
        while(ch!=4);


    return 0;
}

void create()
{
    fstream file;
    file.open("store_record.txt", ios::in | ios::out | ios::app);
    char line[80],name[80];
    int length,rno,qun;
    double cost;
    if(file.is_open())
    {
          cout<<"File opened successfully\n";
          file.seekg(0,ios::end);
          length=file.tellg();
          file.close();
          file.open("store_record.txt", ios::in | ios::out | ios::app);
          if(length==0)
          file<<"Record# "<<"Tool name    "<<"  Quantity "<<"Cost";
          cout<<"Enter record no. of Tool: ";
          cin>>rno;
          cout<<"Enter name of the Tool: ";
          cin>>name;
          cout<<"Enter quatity of the Tool: ";
          cin>>qun;
          cout<<"Enter cost of the Tool: ";
          cin>>cost;
          file<<"\n";
          file.setf(ios::left);
          file.width(8);
          file<<rno;
          file.width(18);
          file<<name;
          file.width(6);
          file<<qun;
          file.width(12);
          file<<cost;

    }
    else
        cout<<"Error while opening the file\n";
}

void display()
{
   char line[80];
   fstream file("store_record.txt", ios::in);
   if(file.is_open())
   {
    cout<<"\nDetails of tool\n";
    while(file.good())
    {
       file.getline(line,80);
       cout<<line<<endl;
    }
    cout<<endl;
   }
   else
    cout<<"Error while opening the file\n";
}

void remov()
{
  fstream f1,f2,f3;
  f1.open("store_record.txt", ios::in);
  f2.open("store_record.txt", ios::in);
  f3.open("temp.txt", ios::out | ios::trunc);
  char rno[5];
  char cmp[80];
  char line[80],l[80];
  if(f1.is_open())
  {
      cout<<"Enter record no.: ";
      cin>>rno;
      f3<<"Record# "<<"Tool name    "<<"  Quantity "<<"Cost"<<endl;
      f2.getline(line,80);
      f1.getline(line,80);
      while(!f2.eof())
      {
          f1.getline(line,80);
          f2>>cmp;
          f2.getline(l,80);
          if(strcmp(rno,cmp))
          {
              f3<<line<<"\n";
          }
      }
      f1.close();
      f2.close();
      f3.close();
      remove("store_record.txt");
      rename("temp.txt","store_record.txt");
  }
  else
  cout<<"Error while opening the file\n";
}
