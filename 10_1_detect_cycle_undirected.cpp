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

    bool isCyclicBfs(unordered_map<int, bool> &visited, int source)
    {
        unordered_map<int, int> parent;
        parent[source] = -1;
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto neighbour : adj[frontNode])
            {
                if (visited[neighbour] == true && neighbour != parent[frontNode])
                {
                    return true;
                }
                else if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(unordered_map<int, bool> &visited, int node, int parent)
    {
        visited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycleDetected = isCyclicDFS(visited, neighbour, node);
                if (cycleDetected)
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }
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
        g.addEdge(u, v, 0);
    }

    unordered_map<int, bool> visited;
    g.printAdjList();
    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (g.isCyclicBfs(visited, i))
            {
                res = true;
                break;
            }
        }
    }
    if (res)
    {
        cout << "Graph is Cyclic using BFS" << endl;
    }
    else
    {
        cout << "Graph is not cyclic using BFS" << endl;
    }
    cout << endl;
    unordered_map<int, bool> visit;
    res = false;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            if (g.isCyclicDFS(visit, i, -1))
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