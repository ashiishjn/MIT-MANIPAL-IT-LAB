#include <iostream>
using namespace std;
int c;
void selectionsort(int a[],int n)
{
    int i,j,sm,s;
    c++;
    for(i=0;i<n-1;i++)
    {
        c++;
        s=i;
        c++;
        sm=a[i];
        c++;
        for(j=i+1;j<n;j++)
        {
            c++;
            c++;
            if(sm>a[j])
            {
                c++;
                sm=a[j];
                c++;
                s=j;
            }
        }
        c++;
        a[s]=a[i];
        c++;
        a[i]=sm;
    }
}
int main()
{
    int i,j,s,sm,n;
    cout<<"Enter the length of array";
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array";
    for(i=0;i<n;i++)
        cin>>a[i];
    selectionsort(a,n);
    cout<<"The step count is "<<c<<endl;
    for(i=0;i<n;i++)
        cout<<" "<<a[i];
    return 0;
}
