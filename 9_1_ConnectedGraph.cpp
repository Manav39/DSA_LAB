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

    void dfs(unordered_map<int, bool> &visited, int node)
    {
        cout << node << "  ";
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
    cout << endl;
    unordered_map<int, bool> visit;
    cout << "DFS Traversal" << endl;
    int totalConnectedComponents = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            totalConnectedComponents++;
            cout << "Elements in Connected Component " << totalConnectedComponents << endl;
            g.dfs(visit, i);
            cout << endl;
        }
    }
    cout << "Total Number of Connected Components : " << totalConnectedComponents << endl;
    if (totalConnectedComponents == 1)
    {
        cout << "It is Connected Graph" << endl;
    }
    else
    {
        cout << "It is not a Connected Graph" << endl;
    }
}