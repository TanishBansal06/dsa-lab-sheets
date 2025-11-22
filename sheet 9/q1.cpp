void bfs(){
  queue<int> q;
  vector<int> vis(V,0);
  q.push(0);
  vis[0] = 1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v : l[u]){
        if(!vis[v]){
            q.push(v);
            vis[v] = 1;
        }
    }
  }
}
