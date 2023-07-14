 private:
    int dx[8]={1,1,-1,-1,-1,0,0,1}; 
    int dy[8]={0,1,-1,0,1,1,-1,-1};  
    void solve(int i,int j,vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0')
          return;
        grid[i][j]='0';  
        for(int k=0;k<8;++k){
            int nx=dx[k]+i;
            int ny=dy[k]+j;
             solve(nx,ny,grid);
        }
        return;
    }
    int n,m;
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here 
        int count=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    count+=1;
                    solve(i,j,grid);
                }
            }
        }
        return count;
    } 
// T.c=o(n*m*8)
// S.c=O(8)+O(8)
