#include <bits/stdc++.h>
int getTotalIslands(int** grid, int m, int n)
{
   // Write your code here.

       
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&& grid[i][j]==1){
                    count++;
                    vis[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        
                        
                        for(int dr=-1;dr<=1;dr++){
                           for(int dc=-1;dc<=1;dc++){
                            int nr=x+dr;
                            int nc=y+dc;
                       
      if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                                vis[nr][nc]=1;
                                q.push({nr, nc});
                            }
                            }    
                        }
                    }
                }
            }
        }
        return count;
    }
