#include<bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        cout<<"Invalid invocation of program..!!!";
        return 0;
    }
    else
    {
        ifstream ob;
        ofstream ob1;

        ob1.open("nf.txt",ios::app);
        ob.open(argv[3],ios::in);

		string s,f,r;
        f=argv[1];
        r=argv[2];
        int len=f.size();
        //cout<<f<<" "<<r<<endl;
        while(!ob.eof())
        {   //cout<<"cutee"<<endl;
            getline(ob,s);
            int loc=s.find(f);
            if(loc!=string::npos)

            {
                s.erase(loc,len);
                s.insert(loc,r);
            }
            ob1<<s<<"\n";
        }
        ob.close();
        ob1.close();
        int result;
        remove(argv[3]);
         result= rename("nf.txt",argv[3]);
  if ( result == 0 )
    puts ( "File successfully renamed" );
  else
    perror( "Error renaming file" );
        return 0;
    }
}
