#include <iostream>
using namespace std;
int vertices, edges;
void DFS(int a[][10], int source, int visited[], int &counter)
{
    int i, j;
    counter++;
    cout << (source + 1) << " --> ";
    visited[source] = 1;
    counter++;
    for (int i = 1; i <= vertices; i++)
    {
        counter++;
        if (a[source][i - 1] == 1 && (!visited[i - 1]))
        {
        counter++;
        DFS(a, i - 1, visited, counter);
        counter++;
        }
    }
    counter++;
    }
int main()
{
    int a[10][10], n, m, x, counter = 0, i, j;
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
    int visited[10];
    for (i = 0; i < vertices; i++)
    visited[i] = 0;
    cout << "\nDFS is : ";
    DFS(a, source - 1, visited, counter);
    cout << "NULL"<< "\n\nNumber of steps : " << counter;
}
