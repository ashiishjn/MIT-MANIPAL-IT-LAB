#include <iostream>
using namespace std;
int counter, edges, vertices;
class Stack
{
    int top;
    int a[100];
    public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty();
    void push(int x);
    int pop();
};
bool Stack::isEmpty()
{
    if (top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack::push(int x)
{
    if (top < 100)
    {
        top++;
        a[top] = x;
    }
    else
    {
        cout << "\nStack is Full !\n";
    }
}
int Stack::pop()
{
    if (!isEmpty())
    {
        return (a[top--]);
    }
    else
    {
        cout << "\nStack is Empty !\n";
        return 0;
    }
}
void DFS(int a[][10], int *visited, int source, int *parent)
{
    counter++;
    visited[source] = 1;
    counter++;
    for (int i = 1; i <= vertices; i++)
    {
        counter++;
        if (a[source][i - 1] == 1 && !visited[i - 1])
        {
            counter++;
            parent[i - 1] = source;
            counter++;
            DFS(a, visited, i - 1, parent);
            counter++;
        }
    }
    counter++;
}
int main()
{
    int a[10][10], counter = 0, i, j;
    cout << "Enter Number of Vertices : ";
    cin >> vertices;
    cout << "Enter Number of Edges : ";
    cin >> edges;
    for (i = 0; i < vertices; i++)
    for (int j = 0; j < vertices; j++)
    a[i][j] = 0;
    int p, q;
    for (i = 1; i <= edges; i++)
    {
        cout << "Enter Source : ";
        cin >> p;
        cout << "Enter Destination : ";
        cin >> q;
        a[p - 1][q - 1] = 1;
    }
    cout << "\nThe Adjacency Matrix is : \n\n";
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Enter Source : ";
    int source;
    cin >> source;
    cout << "Enter Destination : ";
    int destination;
    cin >> destination;
    int visited[10];
    counter++;
    for (i = 0; i < vertices; i++)
    {
        counter++;
        visited[i] = 0;
        counter++;
    }
    counter++;
    int parent[10];
    counter++;
    for (i = 0; i < vertices; i++)
    {
        counter++;
        parent[i] = i;
        counter++;
    }
    counter++;
    DFS(a, visited, source - 1, parent);
    counter++;
    if (!visited[destination - 1])
    {
        counter++;
        cout << "NO path exists!";
    }
    else
    {
        counter++;
        Stack s;
        counter++;
        while (parent[destination - 1] != (destination - 1))
        {
            counter++;
            s.push(destination);
            counter++;
            destination = parent[destination - 1] + 1;
            counter++;
        }
        counter++;
        s.push(destination);
        counter++;
        while (!s.isEmpty())
        {
            counter++;
            cout << s.pop() << " --> ";
        }
        counter++;
    }
    cout << "NULL"<< "\n\nNumber of steps : " << counter;
}
