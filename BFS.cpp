#include <bits/stdc++.h>
using namespace std;

class BFS
{
    int n, a[10][10], s[10], source;

public:
    void read();
    void print();
    void bfs();
};

void BFS::read()
{
    int i, j;
    cout << "Enter number of nodes: " << endl;
    cin >> n;
    cout << "Enter adjacency matrix: " << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    cout << "Enter source node: " << endl;
    cin >> source;
}

void BFS::bfs()
{
    int i, v, u, f, r, q[10];
    for (i = 0; i < n; i++)
        s[i] = 0;
    f = r = 0;
    q[r] = source;
    s[source] = 1;
    while (f <= r)
    {
        u = q[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && s[v] == 0)
            {
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void BFS::print()
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 0)
            cout << "Vertex - " << i << " not reachable." << endl;
        else
            cout << "Vertex - " << i << " reachable." << endl;
    }
}

int main()
{
    BFS b;
    b.read();
    b.bfs();
    b.print();
    return 0;
}