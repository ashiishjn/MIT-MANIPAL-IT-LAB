#include <bits/stdc++.h>
using namespace std;
  
const int MAX = 100;
int store[MAX], n;
int graph[MAX][MAX];
int d[MAX];

bool is_clique(int b)
{
    for (int i = 1; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
            if (graph[store[i]][store[j]] == 0)
                return false;
    }
    return true;
}

int maxCliques(int i, int l)
{
    int max_ = 0;
    for (int j = i + 1; j <= n; j++) 
    {
        store[l] = j;
        if (is_clique(l + 1)) 
        {
            max_ = max(max_, l);
            max_ = max(max_, maxCliques(j, l + 1));
        }
    }
    return max_;
}
int main()
{
    int edges[][2] = { { 1, 2 }, { 2, 3 }, { 3, 1 }, { 4, 2 } };
    int size = 4;
    n = 4;
    for (int i = 0; i < size; i++) 
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
        d[edges[i][0]]++;
        d[edges[i][1]]++;
    }
    cout << maxCliques(0, 1);
    return 0;
}