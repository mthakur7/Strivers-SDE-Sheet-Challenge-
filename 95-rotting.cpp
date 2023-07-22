#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid,int m,int n) {
       
        vector<vector<int>>vis(m,vector<int>(n,0));
         queue<pair<pair<int,int>,int>>q;
         int ans=0;
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
            q.push({{i,j},0});
            vis[i][j]=2;             
            }
            else
            vis[i][j]=0;
        }       
        }      
    
        while(!q.empty()){
          
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            
            q.pop();
           ans=max(t,ans);
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
               
                if(nx<m && nx>=0 && ny<n && ny>=0&&vis[nx][ny]==0&&grid[nx][ny]==1){
                    vis[nx][ny]=2;                    
                    q.push({{nx,ny},t+1});
                   
                }
            }


        } 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)
                return -1;
            }
        }  
             
            
        
        return ans;
    }
