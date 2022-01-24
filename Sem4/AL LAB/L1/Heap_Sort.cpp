#include <iostream>
using namespace std;
int c;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    c++;
    int l = 2 * i + 1;
    c++;
    int r = 2 * i + 2;
    c++;
    c++;
    if (l < n && arr[l] > arr[largest])
    {
        c++;
        largest = l;
    }

    c++;
    if (r < n && arr[r] > arr[largest])
    {
        c++;
        largest = r;
    }
    c++;
    if (largest != i)
    {
        c++;
        swap(arr[i], arr[largest]);
        c++;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        c++;
        heapify(arr, n, i);
        c++;
    }
    for (int i=n-1; i>0; i--)
    {
        c++;
        swap(arr[0], arr[i]);
        c++;
        heapify(arr, i, 0);
        c++;
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
    heapSort(a,n);
    cout<<"The step count is "<<c<<endl;
    cout<<"\nThe numbers in sorted order are\n";
    for(i=0;i<n;i++)
        cout<<"\n"<<a[i];
    return 0;
}
