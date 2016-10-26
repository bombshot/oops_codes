#include<bits/stdc++.h>
using namespace std;

class binary{
	string first,second;
	stack<int> a;
	stack<int> b;
public:
	void getdata();
	void adder();
};
void binary::getdata(){
	cout<<"Enter first binary: ";
	cin>>first;
	for(int i=0;i<first.size();i++){
		a.push((int)first[i]-48);
	}
	cout<<"Enter second binary: ";
	cin>>second;
	for(int i=0;i<second.size();i++){
		b.push((int)second[i]-48);
	}
}
void binary::adder(){
	stack<int> c;
	int sum,carry=0;
	while(!a.empty()&&!b.empty()){
		sum=a.top()+b.top();
		int res=sum+carry;
		if(res==3){
			sum=1;
			carry=1;
		}
		else if(res==2){
			carry=1;
			sum=0;
		}
		else if(res==0){
			sum=0;
			carry=0;
		}
		else{
			sum=1;
			carry=0;
		}
		c.push(sum);
		a.pop();b.pop();
	}
	while(!a.empty()){
		int res=a.top()+carry;
		if(res==2){
			sum=0;
			carry=1;
		}
		else if(res==0){
			sum=0;
			carry=0;
		}
		else{
			sum=1;
			carry=0;
		}
		c.push(sum);
		a.pop();
	}
	while(!b.empty()){
		int res=b.top()+carry;
		if(res==2){
			sum=0;
			carry=1;
		}
		else if(res==0){
			sum=0;
			carry=0;
		}
		else{
			sum=1;
			carry=0;
		}
		c.push(sum);
		b.pop();
	}
	cout<<"Result: "<<carry;
	while(!c.empty()){
		cout<<c.top();
		c.pop();
	}
	cout<<"\n";
}


int main(){
	binary b;
	char flag='y';
	cout<<"-----------BINARY ADDER-----------\n";
	cout<<"Select operation:\n1:Input two binary\n2:Binary addition\n";
	do{
		cout<<"Operation key: ";
		int op;
		cin>>op;
		switch(op){
		case 1:{
			b.getdata();
			break;
		}
		case 2:{
			b.adder();
			break;
		}
		default:{
			cout<<"Invalid key selected\n";
			break;
		}
		}
		cout<<"Do you want to continue: ";
		cin>>flag;
	}while(flag=='y');
	return 0;
}
