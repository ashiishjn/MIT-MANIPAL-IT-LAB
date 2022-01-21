//Program to find Transpose of a matrix using Sparse Row Method
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Sparse{
    public:
    int row;
    int column;
    int value;
    void set(int r, int c, int v){
        row=r;column=c;value=v;
    }
    void display(){
        cout<<row<<' '<<column<<' '<<value<<endl;
    }

};

Sparse* nTranspose(Sparse a[]){
    Sparse *b = new Sparse[a[0].value+1];
    b[0].set(a[0].column,a[0].row,a[0].value);
    int k=1;
    for(int i=0;i<a[0].column;i++){
        for(int j=1;j<=a[0].value;j++){
            if(a[j].column==i)
                b[k++].set(a[j].column,a[j].row,a[j].value);
        }
    }
    return b;

}


int main(){
    int m,n;
    cout<<"Enter the size of the matrix:"<<endl;
    cin>>m>>n;
    int arr[m][n];
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter ["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                count++;
        }
    }
    //Developing a sparse matrix
    Sparse s[count+1];
    s[0].set(m,n,count);
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                s[++k].set(i,j,arr[i][j]);
            }
        }
    }
    cout<<"Matrix before Transposing"<<endl;
    for(int k=0;k<=count;k++){
        s[k].display();
    }

    Sparse *b=nTranspose(s);
    cout<<"Matrix after Transposing"<<endl;
    for(int k=0;k<=count;k++){
        b[k].display();
    }
}