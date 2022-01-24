#include<iostream>
using namespace std;
void MinMax(int arr[],int lo,int hi,int *min,int *max)
{
    if(hi==lo)
    {
        *min=*max=arr[lo];
    }
    else if(hi==lo+1)
    {
        if(arr[hi]<=arr[lo])
        {
            *min=arr[hi];
            *max=arr[lo];
        }
        else
        {
            *max=arr[hi];
            *min=arr[lo];
        }
    }
    else
    {
        int mid=(lo+hi)/2;
        int min1,min2,max1,max2;
        MinMax(arr,lo,mid,&min1,&max1);
        MinMax(arr,mid+1,hi,&min2,&max2);
        if(min1<=min2)
            *min=min1;
        else
            *min=min2;
        if(max1>=max2)
            *max=max1;
        else
            *max=max2;
    }
}
int main()
{
    int num,small,large;
    cout<<"\nEnter the number of elements"<<endl;
    cin>>num;
    int arr[num];
    cout<<"Enter elements\n";
    for(int i=0;i<num;i++)
    cin>>arr[i];
    MinMax(arr,0,num-1,&small,&large);
    cout<<"Smallest is "<<small<<" and largest is "<<large<<endl;
    return 0;
}