/*
-------------------------------------------------------------------------------------------------
=	Write a function in C++ to count and display the number of lines not starting with	=
=	alphabet 'A' present in a text file "STORY.TXT".					=
=	Example:										=
=	If the file "STORY.TXT" contains the following lines,					=
=	The roses are red.									=
=	A girl is playing there.								=
=	There is a playground.									=
=	An aeroplane is in the sky.								=
=	Numbers are not allowed in the password.						=	
=	The function should display the output as 3.						=	
=												=	
-------------------------------------------------------------------------------------------------
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream ob;
	ob.open("jitu.txt");
	
	string s;
		
		int cnt=0;
		getline(ob,s);

		while(!ob.eof())
		{
			
			if(s[0]!='a'&&s[0]!='A')
			cnt++;
			getline(ob,s);
		
		}
		
	ob.close();
	
	cout<<"\n\n*************************************************\n";
	cout<<"\nThe no lines which do not start with A are : "<<cnt;
return 0;

}
