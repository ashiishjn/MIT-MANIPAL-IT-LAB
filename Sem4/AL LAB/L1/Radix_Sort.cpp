#include <iostream>
using namespace std;
int coun;
void radixsort(int a[],int n)
{
    int b[10][20],bc[10],i,j,k,r,l,c=0;
    coun++;
    int largest=a[0],divisor=1;
    coun++;
    for(i=1;i<n;i++)
    {
        coun++;
        if(a[i]>largest)
        {
            coun++;
            largest=a[i];
            coun++;
        }

    }
    while(largest>0)
    {
        coun++;
        c++;
        coun++;
        largest/=10;
        coun++;
    }
    for(i=0;i<c;i++)
    {
        coun++;
        for(j=0;j<10;j++)
        {
            coun++;
            bc[j]=0;
            coun++;
        }
        for(j=0;j<n;j++)
        {
            coun++;
            r=(a[j]/divisor)%10;
            coun++;
            b[r][bc[r]++]=a[j];
            coun++;
        }
        l=0;
        coun++;
        for(j=0;j<=9;j++)
        {
            coun++;
            for(k=0;k<bc[j];k++)
            {
                coun++;
                a[l++]=b[j][k];
                coun++;
            }
        }
        coun++;
        divisor=divisor*10;
    }
}
int main()
{
    int temp=0,i,j,n,f=0;
    cout<<"Enter the length of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    radixsort(a,n);
    cout<<"The step count is "<<coun<<endl;
    cout<<"\nThe numbers in sorted order are\n";
    for(i=0;i<n;i++)
        cout<<"\n"<<a[i];
    return 0;
}
