#include<iostream>
using namespace std;
template<class T>
class vector               //template class
{
	T *v,size;
	public:
	   void accept(T size)                    //accept function to create generic vector
	   {
	   	    this->size=size;
	   	    v=new int[size];
	   	    cout<<"Enter numbers: ";
	   		for(unsigned int i=0;i<size;i++)
            cin>>*(v+i);
	   }

	   void display()                        //display function to display vector
	   {
	   	cout<<"numbers are: ";
	   	cout<<"(";
	   	for(unsigned int i=0;i<size;i++)
	   	 {
	   	   cout<<*(v+i);
	   	   if(i!=size-1)
			cout<<",";
	     }
	   	cout<<")\n";
	   }

	   void multiply()                     //multiply function to multiply each element of vector by a scalar value
	   {
	   	 T num;
	   	 cout<<"Enter the number: ";
	     cin>>num;
	   	 for(unsigned int i=0;i<size;i++)
	   	  v[i]*=num;
	   }

	   void  index_modify(T index)        //to modify value of vector using index
	   {
	   	        int val;
	   			cout<<"Enter new value: ";
	   			cin>>val;
	   			v[index-1]=val;
	   }

	   	void  val_modify(T num)          //to modify value of vector using a value
	   {
	   	int val,flag=0;
	   	for(unsigned int i=0;i<size;i++)
	   	{
	   		if(v[i]==num)
	   		{
	   			cout<<"Enter new value: ";
	   			cin>>val;
	   			flag=1;
	   			break;
	   		}
	   	}

	   	if(flag==1)
	   for(unsigned int i=0;i<size;i++)
	   	{
	   		if(v[i]==num)
	   			v[i]=val;
	   	}
	   }

};
int main()                                  //main function
{
	int size,ch,opt,index,val,num;
	vector<int > v;
	do
	{                                      //menu
		cout<<"\n(1)To create the vector\n";
		cout<<"(2)To modify value of a given element\n";
		cout<<"(3)To multiply by a scalar value\n";
		cout<<"(4)TO displaly the vector in the form(10,20,30,.....)\n";
		cout<<"(5)To exit\n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
		      cout<<"Enter the size of vector: ";
	          cin>>size;
	          v.accept(size);
	          break;
	        case 2:
	        	cout<<"Enter '1' to modify the value by index\n";
	        	cout<<"Enter '2' to modify the value by value\n";
	        	cin>>opt;
	        	if(opt==1)
	        	{
	        		cout<<"Enter index: ";
	        		cin>>index;
	        		v.index_modify(index);
	        	}

	        	else if(opt==2)
	        	{
	        		cout<<"Enter val: ";
	        		cin>>num;
	        		v.val_modify(num);
	        	}

	        	else
	        	cout<<"wrong choice\n";

	         break;
	        case 3:
	          v.multiply();
	          break;
	        case 4:
	          v.display();
	          break;
	        default:
	          cout<<"wrong choice\n";

		}
	}while(ch!=5);

	return 0;

}
