#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        // direction - 1 (Directed Graph)
        // direction - 0 (Undirected Graph)
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {
        cout << "Adjacency List for a given Graph" << endl;
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(unordered_map<int, bool> &visited, int i)
    {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";
            for (auto it : adj[frontNode])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }
    void dfs(unordered_map<int, bool> &visited, int node)
    {
        cout << node << " ";
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(visited, it);
            }
        }
    }
};

int main()
{
    Graph g;
    unordered_map<int, bool> visited;
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;
    int m;
    cout << "Enter the number of edges : ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();
    cout << "BFS Traversal" << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(visited, i);
        }
    }
    cout << endl;
    unordered_map<int, bool> visit;
    cout << "DFS Traversal" << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            g.dfs(visit, i);
        }
    }
}