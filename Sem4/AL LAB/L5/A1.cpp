#include <iostream>
using namespace std;
#define V 5

int maxvertexsearch(bool visited[], int weights[])
{
    int index = -1;
    int maxW = INT_MIN;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false && weights[i] > maxW)
        {
            maxW = weights[i];
            index = i;
        }
    }
    return index;
}
void print(int graph[V][V], int parent[])
{
    int MST = 0;
    for (int i = 1; i < V; i++)
    {
        MST += graph[i][parent[i]];
    }
    cout << "Weight of the maximum Spanning-tree "<< MST << '\n'<< '\n';
    cout << "Edges \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";
    }
}
void maxspanningtree(int graph[V][V])
{
    bool visited[V];
    int weights[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        weights[i] = INT_MIN;
    }
    weights[0] = INT_MAX;
    parent[0] = -1;
    for (int i = 0; i < V - 1; i++)
    {
        int maxVertexIndex = maxvertexsearch(visited, weights);
        visited[maxVertexIndex] = true;
        for (int j = 0; j < V; j++)
        {
            if (graph[j][maxVertexIndex] != 0 && visited[j] == false)
            {

                if (graph[j][maxVertexIndex] > weights[j])
                {
                    weights[j] = graph[j][maxVertexIndex];
                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
    print(graph, parent);
}
int main()
{
    int graph[V][V] = { { 0, 2, 0, 4, 0 },
                        { 2, 0, 1, 2, 5 },
                        { 0, 3, 0, 0, 3 },
                        { 3, 7, 0, 9, 10 },
                        { 0, 2, 3, 11, 0 } };
    maxspanningtree(graph);
    return 0;
}
