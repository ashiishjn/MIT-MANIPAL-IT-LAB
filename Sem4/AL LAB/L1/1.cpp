#include <iostream>
using namespace std;
int c;
int binarysearch(int a[],int n,int num)
{
    int mid;
    c++;
    int low=0;
    c++;
    int high=n-1;
    c++;
    do
    {
        c++;
        mid=(high+low)/2;
        c++;
        if(a[mid]>num)
        {
            c++;
            high=mid-1;
        }
        else if(a[mid]<num)
        {
            low=mid+1;
            c++;
        }
    }while(a[mid]!=num && high>=low);
    c++;
    if(a[mid]==num)
        return 1;
    else
        return 0;
}
int main()
{
    int n,num,i;
    cout<<"Enter the length of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to be searched\n";
    cin>>num;
    int f=binarysearch(a,n,num);
    cout<<"The step count is "<<c<<endl;
    if(f)
        cout<<"Number found";
    else
        cout<<"Number not found";
    return 0;
}
