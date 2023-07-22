#include<bits/stdc++.h>
bool dfs(int n, int p, vector<int>adj[],vector<int>&vis){
    vis[n]=1;
    for(auto x:adj[n]){
        if(!vis[x]){
            vis[x]=1;
           if(dfs(x,n,adj,vis))return true;
        }
        else if(p!=x)return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(int i=0;i<edges.size();i++){
    adj[edges[i][0]].push_back(edges[i][1]);
     adj[edges[i][1]].push_back(edges[i][0]);
    }
   vector<int>vis(n+1,0);
    queue<pair<int,int>>q;
   
    for(int i=1;i<=n;i++){
    if(!vis[i]){
    if(dfs(i,-1,adj,vis)==true)return "Yes";
    }
    }
   return "No";
   
    
}
