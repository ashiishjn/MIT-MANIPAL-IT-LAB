#include <iostream>

using namespace std;
void quicksort(int a[], int low, int high)
{
    int i,j,pivot,temp;
    if(high>low)
    {
        i=low;
        j=high+1; 
        pivot=a[high];
        cout<<pivot;
        do
        {
            do
            {
                i++;
            } while(pivot>a[i]);
            do
            {
                j--;
            } while (pivot<a[j]);
            if(j>i)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        } while (j>i);
        temp=a[low];
        a[low]=a[j];    
        a[j]=temp;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int a[]={11,25,4,56,18,23,7,9,10,87,10,99,15,14};
    quicksort(a,0,13);
    cout<<"The sorted array is "<<endl;
    for(int i=0;i<14;i++)
        cout<<a[i]<<" , ";
}