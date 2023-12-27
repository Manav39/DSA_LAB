#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        cout << "Adjacency List for graph" << endl;
        for (auto it : adj)
        {
            cout << it.first << " -> ";
            for (auto j : it.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisit)
    {
        visited[node] = true;
        dfsvisit[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycleDetected = isCyclicDFS(neighbour, visited, dfsvisit);
                if (cycleDetected)
                    return true;
            }
            else if (dfsvisit[neighbour] == true)
            {
                return true;
            }
        }
        dfsvisit[node] = false;
        return false;
    }
};

int main()
{
    Graph g;
    int n, m;
    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }

    unordered_map<int, bool> visit;
    unordered_map<int, bool> dfsvisit;
    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            if (g.isCyclicDFS(i, visit, dfsvisit))
            {
                res = true;
                break;
            }
        }
    }
    if (res)
    {
        cout << "Graph is Cyclic using DFS" << endl;
    }
    else
    {
        cout << "Graph is not cyclic using DFS" << endl;
    }
    cout << endl;
}