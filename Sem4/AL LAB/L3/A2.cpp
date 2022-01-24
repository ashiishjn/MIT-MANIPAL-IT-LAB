#include<iostream>
#include<queue>

using namespace std;

class Node{
	public:
	int val;
	Node* next = NULL;
};

void add(Node*& head, int val){
	if(!head){
		head = new Node;
		head->val = val;
		return;
	}
	Node* temp = head;
	while(temp->next != NULL)
		temp = temp->next;
		
	Node* newn = new Node;
	newn->val = val;
	temp->next = newn;
}

bool motherVertexHelper(Node* graph[], int n, int src){
	queue<int> q;
	int visited[n];
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	visited[src] = 1;
	int numvis = 1;
	q.push(src);
	
	while(!q.empty()){
		Node* temp = graph[q.front()];
		numvis++;
		q.pop();
		
		while(temp != NULL){
			if(visited[temp->val] == 0){
				visited[temp->val] = 1;
				q.push(temp->val);
			}
			temp = temp->next;
		}
	}
	return (numvis == n);
}

bool Strongly(Node* graph[], int n){
	// if all vertices are M.V. then graph is strongly connected.
	// If any vertex is not M.V. then graph is weakly connceted.
	for(int i=1;i<n;i++){
		if(!motherVertexHelper(graph, n, i)) 
		    return false;
	}
}
int main(){
	int n;
    cout<<"Enter size:";
    cin>>n;
	Node* graph[n+1]= {NULL};
    cout<<"Enter edges:"<<endl;
    int a=0,b=0;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            add(graph[a], b);
        else
            break;
    }
	int visited[n+1] = {0};
	Strongly(graph, n+1)?cout<< "Strongly Connected":cout<< "Not Strongly Connected";
}
