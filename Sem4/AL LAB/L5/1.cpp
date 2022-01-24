#include <iostream>
using namespace std;
#define V 9
int mindist(int dist[], bool sp[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sp[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void print(int dist[])
{
    cout<<"Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<< i<< "\t\t"<<dist[i]<<"\n";
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sp[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sp[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = mindist(dist, sp);
        sp[u] = true;
        for (int v = 0; v < V; v++)
            if (!sp[v] && graph[u][v] && dist[u] != INT_MAX&& dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    print(dist);
}
int main()
{
    int graph[V][V] = { { 0, 3, 0, 2, 0, 0, 0, 8, 0 },
                        { 2, 0, 8, 0, 0, 0, 0, 13, 0 },
                        { 0, 6, 0, 5, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 4, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 5, 1, 9, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 11, 6 },
                        { 6, 11, 0, 0, 0, 0, 13, 0, 7 },
                        { 0, 0, 5, 0, 0, 0, 3, 9, 0 } };
    dijkstra(graph, 0);
    return 0;
}
