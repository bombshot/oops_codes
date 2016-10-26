#include<bits/stdc++.h>
using namespace std;

class book
{
   char a[20];
   char title[20];
   double price;
   char pub[20];
   int no_of_copies;
   public:
       book();
        friend istream& operator >>(istream& cin,book &ob);
        int find(char f[],char t[]);
        int lol();
        void out();
};

book::book()
{
    strcpy(a,"");
    strcpy(title,"");
    price=0.0;
    strcpy(pub,"");
    no_of_copies=0;
}

istream& operator >>(istream& cin,book &ob)
{
    cout<<"enter name of author of book:";
    cin.getline(ob.a,20);cin.getline(ob.a,20);
    
	cout<<"enter title of the book:";
    cin.getline(ob.title,20);
    
	cout<<"enter price of book:";
    cin>>ob.price;
    
	cout<<"enter publication company of book:";
    cin.getline(ob.pub,20);cin.getline(ob.pub,20);
    
	cout<<"number of copies of a book:";
    cin>>ob.no_of_copies;
}

int book::find(char f[],char t[])
{
    int z=1,k=1;
    
    if(strcmp(f,title))
    z=0;
    
    if(strcmp(t,a))
    k=0;
    
  if(z==1 && k==1)
  {
      return no_of_copies;
  }
  
  else
    return 0;

}

int book::lol()
{
    return price;
}

void book::out()
{
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"name of author is:("<<a<<")\n";
    cout<<"name of title is:("<<title<<")\n";
    cout<<"price of book is:("<<price<<")\n";
    cout<<"name of publication is:("<<pub<<")\n";
    cout<<"name of copies available is:("<<no_of_copies<<")\n";
}


int main()
{
    book ob[100];
    int i=0,g,ch;
    char f[20],t[20],c;

    do
    {
        cout<<"\n--------------------menu of operation----------------\n";
        cout<<"1 for entry of new book\n2 for user request\n3 for printing whole list of book\n4 for exit";

        cin>>ch;
        switch(ch)
        {
            case 1:
             cin>>ob[i];
             i++;
            break;
        
    	    case 2:
	            cout<<"\nenter the title of book:";
            	cin.getline(f,20);cin.getline(f,20);
           		cout<<"enter author of book:";
            	cin.getline(t,20);
             	for(int j=0;j<i;j++)
	             {
	                 g=ob[j].find(f,t);
	                 if(g!=0)
	                 {
	                     int n;
	                     cout<<"how many number of copies u want:";
	                     cin>>n;
	                     if(n<=g)
	                        {
	                            cout<<"**required number of copies of book are found**\n";
	                            cout<<"and their cost is:";
	                            int y=ob[j].lol();
	                            cout<<y*n<<"\n";
	                        }
	                     else
	                        cout<<"**sorry we can provide only"<<g<<" number of copies**\n";
	                     break;
	                 }
	             }
	             
	             if(g==0)
	                cout<<"**given title and author u given no match of such book found in our data**\n";
	                break;
	            
          case 3:
          	
               for(int j=0;j<i;j++)
                   ob[j].out();
               break;
          
          case 4:
             return 0;
      
      	default:
      		cout<<"\nInvalid Input \n";
	  
	  }
          
    }
	while(1);
    
	
	return 0;
}
