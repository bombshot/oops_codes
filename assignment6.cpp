#include<iostream>
#include<cstring>
using namespace std;

class Dob
     {
    	int date,mon,year;
      public:
	Dob()
	  {
	    date=mon=year=0;
	  }

    ~Dob()
      {

	  }

	void print()
	  {
	    cout<<"\nDate of birth : "<<date<<"\\"<<mon<<"\\"<<year;
	  }

	void input()
	  {
	    cout<<"\nEnter date of Birth (numerals)  ";
	    cout<<"\nDate: ";
  	    cin>>date;
	    cout<<"\nMonth : ";
	    cin>>mon;
	    cout<<"\nYear : ";
	    cin>>year;
	  }
     };

class address
     {
	int pincode;
	char locality[20];
	char city[15];
	char state[15];
  public:
	address()
	   {
	     pincode=0;
	     strcpy(locality,"");
	     strcpy(city,"");
	     strcpy(state,"");
	   }
	~address()
		{

		}

	void print()
	   {
	     cout<<"\n\nAddress:\n";
	     cout<<"\nLocality : ";
	     cout.write(locality,20);
	     cout<<"\nCity : ";
	     cout.write(city,15);
	     cout<<"\nState : ";
	     cout.write(state,15);
	     cout<<"\nPincode : "<<pincode;
	  }

	void input()
	  {
	     cout<<"\nEnter locality : ";
	     cin.getline(locality,20);
	     cin.getline(locality,20);
	     cout<<"\nEnter city : ";
	     cin.getline(city,15);
	     cout<<"\nEnter state : ";
	     cin.getline(state,15);
	     cout<<"\nEnter pincode : ";
	     cin>>pincode;
	  }
     };



class PerInfo
     {
	long long int telNo;
	char licNo[15];
	address conAds;
    public:
	PerInfo()
	   {
	    telNo=0;
	    strcpy(licNo,"");
	   }
	PerInfo(PerInfo &info)
	   {
	   	telNo=info.telNo;
	   	strcpy(licNo,info.licNo);
	   	conAds=info.conAds;
	   }
	~PerInfo()
	   {

	   }
	void printPer()
	   {
	    cout<<"\nTelephone number: "<<telNo;
	    cout<<"\nDriving license number : "<<licNo;
	    conAds.print();
	   }
	void inputPer()
	   {
	    cout<<"\nEnter telephone number : ";
	    cin>>telNo;
	    cout<<"Enter Driving license number : ";
	    cin>>licNo;
	    conAds.input();
	   }
    };

class AcadInfo
    {
	int roll;
	char cls[6];
	char div;
    public:
	AcadInfo()
	   {
	    roll=0;
	    strcpy(cls,"");
	    div='A';
	   }
	AcadInfo(AcadInfo &info)
	   {
	   	roll=info.roll;
	   	strcpy(cls,info.cls);
	   	div=info.div;
	   }
	~AcadInfo()
	   {
	   }
    void printAcad()
	   {
	    cout<<"\nClass : "<<cls;
 	    cout<<"\nDivision : "<<div;
	    cout<<"\nRoll number : "<<roll;
	   }
	void inputAcad()
	   {
	    cout<<"\nEnter class : ";
	    cin>>cls;
	    cout<<"Enter Division : ";
	    cin>>div;
	    cout<<"Enter Roll number : ";
	    cin>>roll;
	   }
    };
class MedInfo
    {
	Dob dob;
	char bloodgroup[12];
    public:
	MedInfo()
	   {
	    strcpy(bloodgroup,"");
	   }
	MedInfo(MedInfo &info)
	   {
	   	dob=info.dob;
	   	strcpy(bloodgroup,info.bloodgroup);
	   }
	~MedInfo()
	   {
	   }
    void printMed()
	   {
	    dob.print();
	    cout<<"\nBlood Group : ";
	    cout.write(bloodgroup,12);
	   }
	void inputMed()
	   {
	     dob.input();
	     cout<<"\nEnter blood group : ";
	     cin.getline(bloodgroup,12);
	     cin.getline(bloodgroup,12);
	   }
    };

class Student:public PerInfo,public AcadInfo,public MedInfo
    {
	static int count;
	char name[25];
	int regno;
    public:
	Student()
	   {strcpy(name,"");
	    count++;
	    regno=count;
	   }
	Student(Student &S)
	   {
	   	strcpy(name,S.name);
	   	regno=S.regno;
	   	count++;
	    regno=count;
	   }
	~Student()
	   {
	   }
    void display()
	   {
	    cout<<"\n----------Student :"<<regno<<" Info-----------";
	    cout<<"\nName: ";
	    cout.write(name,25);
	    printAcad();
	    printMed();
	    printPer();
	    cout<<"\n----------------------------------------------";
	  }
	void input()
	  {
	    cout<<"\n----------------------------------------------";
	    cout<<"\nEnter name of student : ";
		cin.getline(name,25);
	    cin.getline(name,25);
	    inputAcad();
	    inputMed();
	    inputPer();
	    cout<<"\nYour allotted registration number: "<<regno;
	    cout<<"\n----------------------------------------------";
	  }

   };
   
   int Student::count=10;

class SIS
   {
   	
   int count;
   Student stud[100];
  
  public:
	SIS()
	  {
	   count=0;
	  }
	SIS(SIS &sis)
	  {
	   count=sis.count;
	   for(int i=0;i<count;i++)
	      stud[i]=sis.stud[i];
	  }
	~SIS()
	  {
	  }
	void display()
	  { if(getcount()==0)
	      {cout<<"\nSIS empty!!!";
	       return ;
	      }
	    for(int i=0;i<getcount();i++)
		stud[i].display();
	  }
	void display(int n)
	  { if(getcount()==0 || n>1000+getcount() || n<1001)
	      {cout<<"\nNo such student exist in database...";
	        return ;
	      }
	    stud[n-1001].display();
	  }
	void input()
	  {if(getcount()==100)
	      {cout<<"\nDatabase is complete.\n\tCannot enter more info...";
	        return ;
	      }
	   stud[getcount()].input();
	   count++;
	  }
	  
	int getcount()
	  {
	    return count;
	  }
	  
	friend class Student;
   
   };



int main()
{
	SIS info;
	
    int input;
   char choice;
   
   do
    {
	 cout<<"\n----------STUDENT INFORMATION SYSTEM------------";
   	 cout<<"\n1.Enter information of a student...";
	 cout<<"\n2.Print information of a student...";
	 cout<<"\n3.Print whole SIS...";
	 cout<<"\n4.Print number of students whose info is in SIS...";
	 cout<<"\n5.Exit...";
	 cout<<"\nEnter your choice (1,2,3,4 or 5): ";
	 cin>>input;

	 switch(input)
	      {
			case 1:
					info.input();
	               	break;
	  	
		  	case 2:
			  	int s;
	  		    cout<<"\nEnter id of student: ";
	  		    cin>>s;
	  		    info.display(s);
	  		    break;
	  		
			  case 3:
			  	 info.display();
	  		     break;
	  		     
	  		   case 4:
				 cout<<"\nNumber of student= ";
		  	     cout<<info.getcount();
		  	     break;
			
			case 5:
			return 0;
		
			default:
			cout<<"\nWrong choice...\n";
		  }
	   
	   	 cout<<"\n\nDo you want to continue(y/n): ";
		 cin>>choice;
		 
	}
	while(choice=='y'||choice=='Y');
	
	
	return 0;
}

