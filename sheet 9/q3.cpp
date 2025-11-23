#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, wt;
};
int parent[100];
int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}
void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) parent[b] = a;
}
int main() {
    int V = 4, E = 5;
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    for (int i = 0; i < V; i++)
        parent[i] = i;
    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.wt < b.wt;
    });
    int mstCost = 0;
    cout << "Edges in MST (Kruskal):\n";
    for (int i = 0; i < E; i++) {
        int pu = findParent(edges[i].u);
        int pv = findParent(edges[i].v);
        if (pu != pv) {        
            cout << edges[i].u << " -- " << edges[i].v
                 << "  Weight: " << edges[i].wt << endl;

            mstCost += edges[i].wt;
            unionSet(pu, pv);
        }
    }
    cout << "Total MST Cost = " << mstCost;
}

// b))

#include <iostream>
using namespace std;
int main() {
    int V = 5;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 7, 7},
        {6, 8, 7, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int key[5];       
    bool mstSet[5];   
    int parent[5];   
    for (int i = 0; i < V; i++) {
        key[i] = 99999;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int minKey = 99999, u;
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Edges in MST (Prim):\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i
             << "  Weight: " << key[i] << endl;
    }
}
