#include <iostream>
using namespace std;
int c;
int Knapsack(int W, int wt[], int val[], int i, int** dp)
{
    c++;
    if (i < 0)
    {
        c++;
        return 0;
    }
    c++;
    if (dp[i][W] != -1)
    {
        c++;
        return dp[i][W];
    }
    c++;
    if (wt[i] > W)
    {
        c++;
        dp[i][W] = Knapsack(W, wt, val, i - 1, dp);
        c++;
        return dp[i][W];
    }
    else
    {
        c++;
        dp[i][W] = max(val[i] + Knapsack(W - wt[i], wt, val, i - 1, dp), Knapsack(W, wt, val, i - 1, dp));
        c++;
        return dp[i][W];
    }
}
int knapSack(int W, int wt[], int val[], int n)
{
    c++;
    int** dp;
    c++;
    dp = new int*[n];
    c++;
    c++;
    for (int i = 0; i < n; i++)
    {
        c++;
        dp[i] = new int[W + 1];
        c++;
    }
    c++;
    for (int i = 0; i < n; i++)
    {
        c++;
        c++;
        for (int j = 0; j < W + 1; j++)
        {
            c++;
            dp[i][j] = -1;
            c++;
        }
    }
    c++;
    return Knapsack(W, wt, val, n - 1, dp);
}
int main()
{
    int val[] = {40,35,50,65};
    int wt[] = { 9,6,8,9};
    int W = 25;
    int n = 4;
    cout<<"The profit is "<<knapSack(W, wt, val, n)<<endl;
    cout<<"The step count is "<<c;
    return 0;
}
