// Program to implement MergeSort
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int beg, int mid, int end){
    int i=beg, j=mid+1, index=beg, temp[100], k;
    while((i<=mid) && (j<=end)){
        if(arr[i] < arr[j]){
            temp[index] = arr[i];
            i++;
        }
        else{
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=end){
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else{
        while(i<=mid){
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
        arr[k] = temp[k];
}

void MergeSort(int arr[], int beg, int end){
    if(beg<end){
        int mid=(beg+end)/2;
        MergeSort(arr,beg,mid);
        MergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main(){
    int arr[]={7,322,10,36,1,45};
    print(arr,6);
    MergeSort(arr,0,6);
    print(arr,6);
}