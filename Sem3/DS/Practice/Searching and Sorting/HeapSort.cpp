// Program to implement HeapSort
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Heapify(int arr[],int n, int i){
    int root=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[root])
        root=left;
    if(right<n && arr[right]>arr[root])
        root=right;
    if(root!=i){
        swap(arr[i],arr[root]);
        Heapify(arr,n,root);
    }
}

void HeapSort(int arr[],int n){
    for (int i=n/2-1; i>=0;i--) 
        Heapify(arr,n,i); 
    for (int i=n-1; i>=0; i--){ 
        swap(arr[0],arr[i]); 
        Heapify(arr,i,0); 
    } 
}


int main(){
    int arr[]={7,10,36,1,45};
    print(arr,5);
    HeapSort(arr,5);
    print(arr,5);
}