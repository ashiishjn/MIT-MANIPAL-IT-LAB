#include <iostream>
#include <list>
#include <stack>
using namespace std;
int c;
class Graph
{
    int V;
    list<int>* adj;
    void topological(int v, bool visited[], stack<int>& Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void toposort();
};
Graph::Graph(int V)
{
    c++;
    this->V = V;
    c++;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    c++;
    adj[v].push_back(w);
}
void Graph::topological(int v, bool visited[], stack<int>& Stack)
{
    c++;
    visited[v] = true;
    c++;
    list<int>::iterator i;
    c++;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        c++;
        if (!visited[*i]) topological(*i, visited, Stack);
    }
    c++;
    Stack.push(v);
}
void Graph::toposort()
{
    stack<int> Stack;
    c++;
    bool* visited = new bool[V];
    c++;
    c++;
    for (int i = 0; i < V; i++)
    {
        c++;
        visited[i] = false;
    }
    c++;
    for (int i = 0; i < V; i++)
    {
        c++;
        if (visited[i] == false)
        {
            c++;
            topological(i, visited, Stack);
        }
    }
    c++;
    while (Stack.empty() == false)
    {
        c++;
        cout << Stack.top() << " ";
        c++;
        Stack.pop();
    }
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Following is a Topological Sort of the given graph \n";
    g.toposort();
    cout<<"\nStep count is "<<c;
    return 0;
}
