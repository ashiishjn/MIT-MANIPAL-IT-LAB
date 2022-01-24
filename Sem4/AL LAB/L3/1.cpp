#include <iostream>
#include <list>
using namespace std;
int counter;
class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);
    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    counter++;
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    counter++;
}
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    counter++;
    if (visited[v] == false)
    {
        visited[v] = true;
        counter++;
        recStack[v] = true;
        counter++;
        list<int>::iterator i;
        counter++;
        counter++;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            counter++;
            counter++;
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
            {
            return true;
            }
            else if (recStack[*i])
            {
            return true;
            }
            counter++;
        }
    }
    recStack[v] = false;
    counter++;
    counter++;
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    counter++;
    for (int i = 0; i < V; i++)
    {
        counter++;
        visited[i] = false;
        counter++;
        recStack[i] = false;
        counter++;
    }
    counter++;
    counter++;
    for (int i = 0; i < V; i++)
    {
        counter++;
        counter++;
        if (isCyclicUtil(i, visited, recStack))
        return true;
    }
    return false;
}
int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    counter = 0;
    if (g.isCyclic())
    cout << "Graph contains cycle \n";
    else
    cout << "Graph doesn't contain cycle \n";
    cout << "Number of steps:" << counter;
    return 0;
}
