class Solution {
    private:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>>&vis,queue<pair<int,int>>&q,vector<vector<int>>&grid){ 
        if(i<0 || j<0 || i>=n ||j>=m || vis[i][j]==1 || grid[i][j]==0)
              return ;
        vis[i][j]=1;
        q.push({i,j});
        for(int k=0;k<4;++k){
            int nx=dx[k]+i;
            int ny=dy[k]+j;
            dfs(nx,ny,vis,q,grid);
        }
        return;
    }
    int bfs(int i,int j,queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<int>>&grid){
         int ans=0;
          while(!q.empty()){
              int t=q.size();
              while(t--){
                  auto itr=q.front();
                  q.pop();
                  int x=itr.first;
                  int y=itr.second;
                  for(int k=0;k<4;++k){
                      int nx=dx[k]+x;
                      int ny=dy[k]+y;
                      if(nx>=0 && nx<n && ny>=0 && ny<m){
                          if(vis[nx][ny]==1)
                              continue;
                          if(grid[nx][ny]==1){
                              return ans;
                          }
                          vis[nx][ny]=1;
                          q.push({nx,ny});
                      }
                  }
              }
              ans+=1;
          }
        return ans;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
          n=grid.size();
          m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
         for(int i=0;i<n;++i){
             for(int j=0;j<m;++j){
                 if(grid[i][j]==1){
                     // vis[i][j]=1;
                     dfs(i,j,vis,q,grid);
                     int ans=bfs(i,j,q,vis,grid);
                     return ans;
                 }
             }
         }
        return 0;
    }
};
// T.C=o(n*m)+o(n*m)
// S.C=o(n*m)
