void dfs(int node,vector<int>adj[],vector<int>&ds,vector<int>&vis){
vis[node]=1;
ds.push_back(node);
for(auto x: adj[node]){
    if(!vis[x]){
        dfs(x,adj,ds,vis);
    }
}
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>adj[V];
    for(int i=0;i<E;i++){
    adj[edges[i][0]].push_back(edges[i][1]);
     adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int>vis(V,0);
     vector<vector<int>>ans;
    for(int i=0;i<V;i++){
      if (!vis[i]){
        vector<int> ds;
        dfs(i, adj, ds, vis);
        ans.push_back(ds);
      }
    }
    return ans;
}
