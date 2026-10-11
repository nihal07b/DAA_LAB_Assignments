#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int V, vector<pair<int, int>> adj[], int source)
{
    vector<int> dist(V, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int wt = edge.second;

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source vertex "
         << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i
             << " -> Distance = "
             << dist[i] << endl;
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter source destination weight:\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(V, adj, source);

    return 0;
}
