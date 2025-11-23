#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;

    for (int child : adj[node]) {
        if (!vis[child])
            dfs(child, adj, vis);
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    vector<int> vis(V, 0);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }
    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            components++;
            dfs(i, adj, vis);
        }
    }
    cout << components;
    return 0;
}
