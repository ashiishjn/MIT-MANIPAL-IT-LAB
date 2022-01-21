// Program to implement Binary Search
#include <iostream>
using namespace std;
int binarysearch(int a[],int n, int elem){
    int low=0, mid, high=n-1;
    while(low<high){
        mid=(low+high)/2;
        if(elem<a[mid]){
            high=mid-1;}
        else if(elem>a[mid]){
            low=mid+1;
        }
        else{
            cout<<"Element found at "<<mid;
            return 0;
        }
    cout<<"Element not found";
    return -1;
    }

}
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter the element at position "<<i<<":\n";
        cin>>a[i];
    }
    cout<<"Enter the element to search for:";
    int elem;
    cin>>elem;
    binarysearch(a,n,elem);}