#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int **adj;
    int size;

public:
    Graph(int vertices) : size(vertices)
    {
        adj = new int *[size];
        for (int i = 0; i < size; i++)
        {
            adj[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void printAdjMatrix()
    {
        cout << "Matrix" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int src, int dest)
    {
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }

    void bfs(int start, vector<bool> &visited)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.pop();
            for (int i = 0; i < size; i++)
            {
                if (!visited[i] && adj[front][i] == 1)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void dfs(int start, vector<bool> &visited)
    {
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < size; i++)
        {
            if (!visited[i] && adj[start][i] == 1)
            {
                dfs(i, visited);
            }
        }
    }

    bool isCyclicBfs(int start, vector<bool> &visited)
    {
        vector<int> parent(size);
        parent[start] = -1;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int i = 0; i < size; i++)
            {
                if (visited[i] == true && i != parent[front])
                {
                    return true;
                }
                else if (!visited[i] && adj[front][i] == 1)
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(int start, int parent, vector<bool> &visited)
    {
        visited[start] = true;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i] && adj[start][i] == 1)
            {
                bool check = isCyclicDFS(i, start, visited);
                if (check)
                    return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of vertices : " << endl;
    cin >> n;
    cout << "Enter the number of edges : " << endl;
    cin >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printAdjMatrix();
    // vector<bool> visit(n, false);
    // int connectComponents = 0;
    // cout << "BFS" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visit[i])
    //     {
    //         connectComponents++;
    //         g.bfs(i, visit);
    //     }
    // }
    // cout << endl;
    // cout << "Connected Compoenents : " << connectComponents << endl;
    // if (connectComponents == 1)
    // {
    //     cout << "Graph is connected using BFS" << endl;
    // }
    // else
    // {
    //     cout << "Graph is Not connected using BFS" << endl;
    // }
    // cout << endl;
    // vector<bool> visited(n, false);
    // connectComponents = 0;
    // cout << "DFS" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         connectComponents++;
    //         g.dfs(i, visited);
    //     }
    // }
    // cout << endl;
    // cout << "Connected Compoenents : " << connectComponents << endl;
    // if (connectComponents == 1)
    // {
    //     cout << "Graph is connected using DFS" << endl;
    // }
    // else
    // {
    //     cout << "Graph is Not connected using DFS" << endl;
    // }
    // cout << endl;
    bool res = false;
    vector<bool> visi(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visi[i])
        {
            if (g.isCyclicBfs(0, visi))
            {
                res = true;
                break;
            }
        }
    }
    if (res)
    {
        cout << "There is a cycle using BFS" << endl;
    }
    else
    {
        cout << "There is no cycle using BFS" << endl;
    }
    // vector<bool> visitt(n, false);
    // bool res;
    // for (int i = 0; i < n; i++)
    // {
    //     if (g.isCyclicDFS(0, -1, visitt))
    //     {
    //         if (res == true)
    //         {
    //             break;
    //         }
    //     }
    // }
    // if (res)
    //     cout << "Cycle exists" << endl;
    // else
    //     cout << "Dosent exists" << endl;

    return 0;
}
