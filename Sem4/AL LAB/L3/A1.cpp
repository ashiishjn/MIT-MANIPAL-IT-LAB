// C++ program to print connected components in an undirected graph 
#include<iostream> 
#include <list> 
using namespace std; 

class Graph 
{ 
    int V;
    list<int> *adj; 
  
    
    void DFS(int v, bool visited[]); 
    public: 
    Graph(int V); 
    void addEdge(int v, int w); 
    void connectedComponents(); 
}; 

void Graph::connectedComponents() { 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
    for (int v=1; v<V; v++) { 
        if (visited[v] == false) {  
            DFS(v, visited); 
            cout << "\n"; 
        } 
    } 
} 
  
void Graph::DFS(int v, bool visited[]) { 
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFS(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
int main() { 
    int n;
    cout<<"Enter size:";
    cin>>n;
	Graph G(n+1);
    cout<<"Enter edges:"<<endl;
    int a=0,b=0;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            G.addEdge(a, b);
        else
            break;
    }
    cout << "Following are connected components \n"; 
    G.connectedComponents(); 
  
    return 0; 
}
