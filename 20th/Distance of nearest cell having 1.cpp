class Solution 
{ 
    private:
    int n,m;
    int dx[8]={-1,1,0,0};
    int dy[8]={0,0,1,-1};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    ans[i][j]=0;
                }
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            int x=itr.first;
            int y=itr.second;
            for(int k=0;k<4;++k){
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int dis=ans[x][y];
                    dis+=(abs(nx-x)+abs(ny-y));
                    int temp=abs(nx-x)+abs(ny-y);
                    if(ans[nx][ny]>dis){
                        ans[nx][ny]=dis;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
	}
};
// T.C=O(n*m)
// S.C=O(n*m)
