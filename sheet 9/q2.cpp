void dfshelper(vector<int> &vis,int u){
    vis[u] = 1;
    for(int v : l[u]){
        if(!vis[v]){
        dfshelper(vis,v);
        }
    }
}
void dfs(){
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfshelper(vis,i);
        }
    }
}
