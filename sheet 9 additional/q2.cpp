#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int,int>> Node;  
int main() {
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    dist[0][0] = grid[0][0];
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({grid[0][0], {0,0}});
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int cost = top.first;
        int r = top.second.first;
        int c = top.second.second;
        if (r == m-1 && c == n-1)
            break;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];
                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
    }
    cout << dist[m-1][n-1];  
    return 0;
}
