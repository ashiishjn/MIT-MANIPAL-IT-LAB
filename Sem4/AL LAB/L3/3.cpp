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

bool path(Node* graph[], int visited[], int src, int dest){
	Node* temp = graph[src];
	while(temp != NULL){
		if(visited[temp->val] == 0){
			if (temp->val == dest || path(graph, visited, temp->val, dest)){
				visited[temp->val] = 1;
				return true;
			}
		}
		temp = temp->next;
	}
	return false;
}

bool connected(Node* graph[], int n){
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			int visited[n]={0};
			if(!(path(graph, visited, i, j) || path(graph, visited, j,i))){
				return false;
			} 
		}
	}
	return true;
}

int main(){
	int n;
    cout<<"Enter size:";
    cin>>n;
	Node* graph[n+1]= {NULL};
    cout<<"Enter edges:"<<endl;
    int a, b;
    while(true){
        cin>>a>>b;
        if(a!=-1 && b!=-1)
            add(graph[a], b);
        else
            break;
    }
    connected(graph,n+1)?cout<<"Graph connected\n":cout<<"Graph disconnected\n";
}
