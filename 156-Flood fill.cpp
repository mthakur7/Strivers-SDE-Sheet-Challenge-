 #include <bits/stdc++.h>
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     //vector<vector<int>>vis(image.size(),(vector<int>(image[0].size(),0)));
        queue<pair<int,int>>q;
     
             q.push({sr,sc});             
             int last= image[sr][sc];
             image[sr][sc]=color;
              while(!q.empty()){
                  int x=q.front().first;
                  int y=q.front().second;
                  q.pop();
                  int dx[]={-1,0,1,0};
                  int dy[]= {0,-1,0,1};
                  for(int k=0;k<4;k++){
                      int nx=x+dx[k];
                      int ny=y+dy[k];

            if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && image[nx][ny]==last &&image[nx][ny]!=color){
                          
                          image[nx][ny]=color;
                          q.push({nx,ny});
                      }
                  }
              }
  
        
        return image; 
    }
