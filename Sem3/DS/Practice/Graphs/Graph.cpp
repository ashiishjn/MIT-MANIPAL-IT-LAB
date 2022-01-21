#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add(int arr[20][20],int n, int head, int tail){
    arr[head][tail]=1;
    // arr[tail][head]=1;
}

void DFS(int arr[20][20],int n,int source){
    bool visited[n]={false};
    stack <int> s;
    s.push(source);
    visited[source]=true;
    while(!s.empty()){
        int c=s.top();
        s.pop();
        for(int i=0;i<n;i++){
            if(arr[c][i]==1 && !visited[i]){
                visited[i]=true;
                s.push(i);
            }
        }
        cout<<c<<" ";
        for(int i=0;i<n;i++){
            cout<<visited[i]<<" ";
        }
        cout<<endl;
    }
}
void BFS(int arr[20][20],int n,int source){
    bool visited[n]={false};
    queue <int> s;
    s.push(source);
    visited[source]=true;
    while(!s.empty()){
        int c=s.front();
        s.pop();
        for(int i=0;i<n;i++){
            if(arr[c][i]==1 && !visited[i]){
                visited[i]=true;
                s.push(i);
            }
        }
        cout<<c<<" ";
        for(int i=0;i<n;i++){
            cout<<visited[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n=9;
    int G[20][20]={0};
    add(G,n,0,1);
    add(G,n,0,4);
    add(G,n,0,3);
    add(G,n,1,2);
    add(G,n,1,4);
    add(G,n,2,5);
    add(G,n,3,4);
    add(G,n,3,6);
    add(G,n,4,5);
    add(G,n,4,7);
    add(G,n,6,4);
    add(G,n,6,7);
    add(G,n,7,5);
    add(G,n,7,8);
    cout<<endl<<endl<<"M ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        for(int j=0;j<n;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<"D ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    DFS(G,n,0);


    cout<<endl<<endl<<"B ";
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    BFS(G,n,0);
}
