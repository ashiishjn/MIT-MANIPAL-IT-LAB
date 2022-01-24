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

void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->val << " ";
		temp = temp->next;
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
    cout<<"Before Transpose:"<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<"->";
        display(graph[i]);
        cout<<endl;
    }

    Node* trans[n+1]= {NULL};
    for(int i=1;i<n+1;i++){
        Node *curr=graph[i];
        while(curr){
            add(trans[curr->val],i);
            curr=curr->next;
        }
    }
    
    cout<<"After Transpose:"<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<"->";
        display(trans[i]);
        cout<<endl;
    }
}
