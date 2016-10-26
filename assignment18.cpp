#include<iostream>
using namespace std;
template<typename  T>
 void Selection_Sort(T ar[],int n)
{
    for(unsigned i=0;i<n-1;i++)
    {
         int min=i;
       for(unsigned j=i+1;j<n;j++)
       {
          . if(ar[j]<ar[min])
           {
              min=j;
           }
       }
          T temp=ar[i];
          ar[i]=ar[min];
          ar[min]=temp;
    }
}

int main()
{
    int n;
    cin>>n;
    double ar[n];
    for(unsigned int i=0;i<n;i++)
        cin>>ar[i];
    Selection_Sort(ar,n);
    for(unsigned int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    return 0;
}
