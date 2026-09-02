// Nihal
// 25/DA/048
#include <iostream>
#include <vector>
using namespace std;

// DFS function
void DFS(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);

    cout << "\nConnected Components:\n";
    int componentCount = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            DFS(i, graph, visited);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components = " << componentCount << endl;

    return 0;
}