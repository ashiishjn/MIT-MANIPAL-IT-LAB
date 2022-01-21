// Program to implement Bubble Sort
#include <iostream>
using namespace std;
void bubbleSort(int a[], int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
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
    bubbleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}