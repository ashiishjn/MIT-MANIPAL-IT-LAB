#include<iostream>

using namespace std;

void traceback(int **kay,int i,int j)
{
    if(i==j)
    return;
    traceback(kay,i,kay[i][j]);
    traceback(kay,kay[i][j]+1,j);
    cout<<"Multiply M "<<i<<", "<<kay[i][j]<<" and M "<<(kay[i][j]+1)<<", "<<j<<endl;
}
void matrixChain(int r[],int numr)
{
    numr-=1;
    int arr[numr][numr];
    int *kay[numr];
    for(int i=0;i<numr;i++)
    kay[i]=new int[numr];
    for(int i=0;i<numr;i++)
    {
        for(int j=0;j<numr;j++)
        {
            arr[i][j]=kay[i][j]=-10;
        }
    }
    int i=0,j=0,start=i;
    while(i<numr && j<numr)
    {
        if(i==j)
        {
            arr[i][j]=0;
        }
        else if(i<j)
        {
            int k,min=-1,temp,minK;
            for(k=i;k<j;k++)
            {
                temp=arr[i][k]+arr[k+1][j]+r[i]*r[k+1]*r[j+1];
                if(min==-1)
                {
                    min=temp;
                    minK=k;
                }
                else if(temp<min)
                {
                    min=temp;
                    minK=k;
                }
            }
            arr[i][j]=min;
            kay[i][j]=minK;
        }
        if(j==numr-1 && i<=numr-1)
        {
            i=0;
            j=++start;
            continue;
        }
        i++;
        j++;
    }
    cout<<"\nThe matrix is "<<endl;
    for(int i=0;i<numr;i++)
    {
        for(int j=0;j<numr;j++)
            if(arr[i][j]==-10)
                cout<<" ";
            else
                cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nThe matrix is "<<endl;
    for(int i=0;i<numr;i++)
    {
        for(int j=0;j<numr;j++)
            if(kay[i][j]==-10)
                cout<<" ";
            else
                cout<<kay[i][j]<<" ";
        cout<<endl;
    }
    traceback(kay,0,numr-1);
}
int main()
{
    int size;
    cout<<"\nEnter size of r"<<endl;
    cin>>size;
    int r[size];
    cout<<"\nPopulate r"<<endl;
    for(int i=0;i<size;i++)
        cin>>r[i];
    matrixChain(r,size);
    return 0;
}