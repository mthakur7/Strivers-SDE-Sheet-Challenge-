 
#include<bits/stdc++.h>
void dfs(int n, stack<int>&st, vector<int>adj[],vector<int>&vis){
    vis[n]=1;
    for(auto x:adj[n]){
        if(!vis[x]){
            vis[x]=1;
           dfs(x,st,adj,vis);
        }
       
    }
   st.push(n);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
// Write your code here.
    vector<int>adj[n];
    for(int i=0;i<e;i++){
    adj[edges[i][0]].push_back(edges[i][1]);
  
    }
   vector<int>vis(n,0);
    queue<pair<int,int>>q;
   stack<int>st;
    for(int i=0;i<n;i++){
    if(!vis[i]){
    dfs(i,st,adj,vis);
    }
    }
    vector<int>ans;
    while(st.size()){
      
        ans.push_back(st.top());
        st.pop();
    }

   return ans;
   
}
