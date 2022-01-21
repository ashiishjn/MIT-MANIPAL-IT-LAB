//Program to find the fast transpose of a matrix using Sparse Row Method
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Sparse{
    public:
    int row;
    int column;
    int value;
    void set(int r, int c, int v){
        row=r;column=c;value=v;
    }
    void FTranspose(Sparse a[], Sparse b[]){
        int r=a[0].row;
        int c=a[0].column;
        int v=a[0].value;
        int frequency[c]={0};
        int start[c];
        b[0].set(a[0].column,a[0].row,a[0].value);
        if(v>0){
            for(int i=1;i<=v;i++){
                frequency[a[i].column]++;
            }
            start[0]=1;
            for(int i=1;i<c;i++){
                start[i]=start[i-1]+frequency[i-1];
            }
            for(int i=0;i<=v;i++){
                int j=start[a[i].column]+1;
                b[j++].set(a[i].column,a[i].row,a[i].value);
            }
        }
    }
    void display(){
        cout<<row<<' '<<column<<' '<<value<<" "<<endl;
    }

};


int main(){
    //Accepting the input in the Square Matrix form
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

    //Original Matrix
    cout<<"Matrix before Transposing"<<endl;
    for(int k=0;k<=count;k++){
        s[k].display();
    }

    Sparse b[count+1], temp;
    cout<<"Matrix after Transposing"<<endl;
    temp.FTranspose(s,b);
    for(int k=0;k<=count;k++){
        b[k].display();
    }
}