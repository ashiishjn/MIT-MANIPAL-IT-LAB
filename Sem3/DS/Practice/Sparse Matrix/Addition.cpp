//Program to implement the addition of Sparse Matrix
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Sparse{
    public:
    int row, column, value;
    void set(int r, int c, int v){
        row=r;
        column=c;
        value=v;
    }
    void print(){
        cout<<row<<" "<<column<<" "<<value<<endl;
    }
};

void display(Sparse s[]){
    if(!s)
        return;
    int k=1;
    for(int i=0;i<s[0].row;i++){
        for(int j=0;j<s[0].column;j++){
            if(i==s[k].row && s[k].column==j)
                cout<<s[k++].value<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

Sparse* add(Sparse s[], Sparse t[]){
    if(s[0].row!=t[0].row ||s[0].column!=t[0].column)
        return NULL;
    Sparse *res= new Sparse[s[0].value+t[0].value+1];
    int i=1,j=1,k=1;
    while(i<=s[0].value && j<=t[0].value){
        if(s[i].row<t[j].row){
            res[k].set(s[i].row,s[i].column,s[i].value);
            i++;
        }
        else if(s[i].row>t[j].row){
            res[k].set(t[j].row,t[j].column,t[j].value);
            j++;
        }
        else{
            if(s[i].column<t[j].column){
                res[k].set(s[i].row,s[i].column,s[i].value);
                i++;
            }
            else if(s[i].column>t[j].column){
                res[k].set(t[j].row,t[j].column,t[j].value);
                j++;
            }
            else{
                res[k].set(s[i].row,s[i].column,s[i].value+t[j].value);
                i++;
                j++;
            }
        }
        k++;
    }
    while(i<=s[0].value){
        res[k++].set(s[i].row,s[i].column,s[i].value);
        i++;
    }
    while(j<=t[0].value){
        res[k++].set(t[j].row,t[j].column,t[j].value);
        j++;
    }
    res[0].set(s[0].row,s[0].column,k-1);
    return res;
}

Sparse* create(){
    int m,n;
    cout<<"Enter the size for matrix:"<<endl;
    cin>>m>>n;
    int arr[m][n];
    int nonzeros=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter ["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                nonzeros++;
        }
    }
    Sparse* s= new Sparse[nonzeros+1];
    s[0].set(m,n,nonzeros);
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0)
                s[k++].set(i,j,arr[i][j]);
        }
    }
    return s;
}

int main(){
    Sparse *s=create();    
    Sparse *t=create();    
    Sparse *sum=add(s,t);    
    display(s);
    display(t);
    display(sum);
}