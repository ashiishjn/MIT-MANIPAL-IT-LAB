#include <iostream>
using namespace std;
int x;
void profitdensity(int wt[], int p[], int c)
{
    int profit = 0;
    double den[8];
    int cap=0,pos;
    x++;
    x++;
    for(int j=0;j<8;j++)
    {
        x++;
        den[j]=(double)p[j]/wt[j];
    }
    for(int j=0;j<8;j++)
    {
        x++;
        double max=0.0;
        x++;
        for(int i=0;i<8;i++)
        {
            x++;
            if(den[i]>max && den[i]!=50.0)
            {
                x++;
                x++;
                max=den[i];
                pos=i;
            }
        }
        x++;
        cap+=wt[pos];
        if(cap<=c)
        {
            x++;
            profit+=p[pos];
            x++;
            den[pos]=50.0;
        }
        else
        {
            x++;
            break;
        }
    }
    x++;
    cout<<"Maximum profit is "<<profit;
}
int main()
{
    int wt[]={5,8,3,8,18,3,7,6};
    int p[]={200,40,50,87,90,120,100,60};
    int c = 40;
    profitdensity(wt,p,c);
    cout<<"\nThe step count is "<<x;
    return 0;
}
