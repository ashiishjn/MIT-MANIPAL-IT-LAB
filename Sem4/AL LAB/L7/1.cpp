#include<iostream>
#define N 100
using namespace std;
class Matrix
{
public:
    int order;
    int **arr=NULL;
    //methods
    void print();
    void populate();
    Matrix add(Matrix m2,int u1,int u2,int l1,int l2,int factor);
    Matrix subtract(Matrix m2,int u1,int u2,int l1,int l2,int factor);
    Matrix multiply(Matrix m2,int l1,int l2,int u1,int u2,int factor);
    Matrix strassens(Matrix m1,Matrix m2,int u1,int u2,int l1,int l2,int factor);
    //Constructor
    Matrix(int order);
};
//factor is order of resultant matrix
Matrix Matrix::multiply(Matrix m2,int u1,int u2,int l1,int l2,int factor)
{
    Matrix *result;
    result=new Matrix(factor);
    int temp,ival;
    for(int i=0;i<factor;i++)
    {
        for(int j=0;j<factor;j++)
        {
        temp=0;
        for(int t=0;t<factor;t++)
        {
            temp+=arr[i+u1][t+l1]*m2.arr[t+u2][j+l2];
        }
        result->arr[i][j]=temp;
        }
    }
    return *result;
}
Matrix Matrix::add(Matrix m2,int u1,int u2,int l1,int l2,int factor)
{
    Matrix *result;
    result=new Matrix(factor);
    for(int i=u1,k=u2,q=0;i<(u1+factor);i++,k++,q++)
    {
        for(int j=l1,l=l2,r=0;j<(l1+factor);j++,l++,r++)
        result->arr[q][r]=arr[i][j]+m2.arr[k][l];
    }
    return *result;
}
Matrix Matrix::subtract(Matrix m2,int u1,int u2,int l1,int l2,int factor)
{
    Matrix *result;
    result=new Matrix(factor);
    for(int i=u1,k=u2,q=0;i<(u1+factor);i++,k++,q++)
    {
        for(int j=l1,l=l2,r=0;j<(l1+factor);j++,l++,r++)
        result->arr[q][r]=arr[i][j]-m2.arr[k][l];
    }
    return *result;
}
Matrix strassens(Matrix m1,Matrix m2,int u1,int u2,int l1,int l2,int factor)
{
    Matrix C(factor);
    if(factor<=2)
    {
        C=m1.multiply(m2,u1,u2,l1,l2,factor);
    }
    else
    {
        int mi=factor/2;
        Matrix C1(mi),C2(mi),C3(mi),C4(mi),D(mi),E(mi),F(mi),G(mi),H(mi),I(mi),J(mi);
        D=strassens(m1,m2.subtract(m2,0,mi,mi,mi,mi),0,0,0,0,mi);
        E=strassens(m1,m2.subtract(m2,mi,0,0,0,mi),mi,0,mi,0,mi);
        F=strassens((m1.add(m1,mi,mi,0,mi,mi)),m2,0,0,0,0,mi);
        G=strassens((m1.add(m1,0,0,0,mi,mi)),m2,0,mi,0,mi,mi);
        H=strassens(m1.subtract(m1,mi,0,0,0,mi),m2.add(m2,0,0,0,mi,mi),0,0,0,0,mi);
        I=strassens(m1.subtract(m1,0,mi,mi,mi,mi),m2.add(m2,mi,mi,0,mi,mi),0,0,0,0,mi);
        J=strassens(m1.add(m1,0,mi,0,mi,mi),m2.add(m2,0,mi,0,mi,mi),0,0,0,0,mi);
        C1=((E.add(I,0,0,0,0,mi)).add(J,0,0,0,0,mi)).subtract(G,0,0,0,0,mi);
        C2=D.add(G,0,0,0,0,mi);
        C3=E.add(F,0,0,0,0,mi);
        C4=((D.add(H,0,0,0,0,mi)).add(J,0,0,0,0,mi)).subtract(F,0,0,0,0,mi);
        //Unwinding phase, combine back into C
        for(int i=0;i<factor;i++)
        {
            for(int j=0;j<factor;j++)
            {
                if(i<mi && j<mi)
                C.arr[i][j]=C1.arr[i][j];
                else if(i<mi && j>=mi)
                C.arr[i][j]=C2.arr[i][j-mi];
                else if(i>=mi && j<mi)
                C.arr[i][j]=C3.arr[i-mi][j];
                else
                C.arr[i][j]=C4.arr[i-mi][j-mi];
            }
        }
    }
    return C;
}
Matrix::Matrix(int order)
{
    this->order=order;
    arr=new int*[order];
    for(int i=0;i<order;i++)
    arr[i]=new int[order];
}
void Matrix::print()
{
    if(arr==NULL)
    {
        cout<<"ERROR, Print NULL"<<endl;
        return;
    }
    cout<<endl;
    for(int i=0;i<order;i++)
    {
        for(int j=0;j<order;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
void Matrix::populate()
{
    for(int i=0;i<order;i++)
    {
        for(int j=0;j<order;j++)
        {
            cin>>arr[i][j];
        }
    }
}
int main()
{
    int num;
    cout<<"\nEnter the order of the matrices"<<endl;
    cin>>num;
    Matrix M1(num),M2(num),M3(num/2);
    cout<<"\nPopulate both the matrices"<<endl;
    M1.populate();
    M2.populate();
    M3=strassens(M1,M2,0,0,0,0,num);
    M3.print();
    return 0;
}