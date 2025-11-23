#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    vector<vector<pair<int,int>>> adj(N+1);
    for (auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(N+1, 1e9);
    dist[K] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});
    while (!pq.empty()) {
        auto top = pq.top(); 
        pq.pop();
        int d = top.first;
        int node = top.second;
        for (auto &nbr : adj[node]) {
            int v = nbr.first;
            int w = nbr.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == 1e9) { 
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }
    cout << ans;
    return 0;
}
