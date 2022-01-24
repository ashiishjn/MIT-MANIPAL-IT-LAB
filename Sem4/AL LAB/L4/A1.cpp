// Program to check if a graph is bipartite or not

#include <iostream>
using namespace std;

class Graph{
    int n;
    int* *adj;
    public:
    Graph(int no){
        n=no+1;
        
        adj = new int*[n];
        for(int i=1;i<n;i++)
            adj[i] = new int[n];

        for(int i=1;i>n;i++){
            for(int j=1;j<n;j++){
                adj[i][j]=0;
            }
        }
    }

    void addEdge(int i, int j){
        adj[i][j]=1;
    }

    void printMatrix(){
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                cout<<adj[i][j]<<" ";
            }
        cout<<"\n";
        }
    }
    
};

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    Graph G(n);
    cout<<"Enter edges:"<<endl;
    int a, b;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            G.addEdge(a,b);
        else
            break;
    }
}