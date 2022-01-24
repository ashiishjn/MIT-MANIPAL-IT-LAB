#include<iostream>

using namespace std;

int knapsack(int weight[],int profit[],int C,int i)
{
    int mat[i][C+1];
    for(int u=i-1;u>=0;u--)
    {
        if(u==i-1)
        {
            for(int v=0;v<=C;v++)
            {
                if(weight[u]<=v)
                mat[u][v]=profit[u];
                else
                mat[u][v]=0;
            }
        }
        else
        {
            for(int v=0;v<=C;v++)
            {
                if(weight[u]>v)
                    mat[u][v]=mat[u+1][v];
                else
                    mat[u][v]=max(mat[u+1][v],mat[u+1][v-weight[u]]+profit[u]);
            }
        }
    }
    int k=0,l=C;
    cout<<endl;
    while(k<i && l>=0)
    {
        if(mat[k][l]!=mat[k+1][l] && l-weight[k]>=0)
        {
            cout<<k<<" selected"<<endl;
            l-=weight[k];
        }
        k++;
    }
    cout<<endl;
    for(int u=i-1;u>=0;u--)
    {
        for(int j=0;j<=C;j++)
        cout<<mat[u][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return mat[0][C];
}
int main()
{
    int num,cap;
    cout<<"\nEnter the number of items"<<endl;
    cin>>num;
    int weight[num],profit[num];
    cout<<"\nEnter the weight and profit for every item"<<endl;
    for(int i=0;i<num;i++)
        cin>>weight[i]>>profit[i];
    cout<<"\nEnter the capacity"<<endl;
    cin>>cap;
    cout<<"\nThe max profit achieveable is "<<knapsack(weight,profit,cap,num);
    return 0;
}