#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;

    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(Edge edges[], int V, int E) {
    sort(edges, edges + E, compare);

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in MST:\n";

    int count = 0, i = 0, totalWeight = 0;

    while (count < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(parent, next.src);
        int y = find(parent, next.dest);

        if (x != y) {
            cout << next.src << " - "
                 << next.dest << " : "
                 << next.weight << endl;

            totalWeight += next.weight;
            Union(parent, x, y);
            count++;
        }
    }

    cout << "Total Weight = " << totalWeight << endl;
}

int main() {
    int V = 4;
    int E = 5;

    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}