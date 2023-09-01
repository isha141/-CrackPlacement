class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here 
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            int t=q.size();
            bool flag=0;
            while(t--){
                auto itr=q.front();
                q.pop();
                for(int k=0;k<4;++k){
                    int nx=dx[k]+itr.first;
                    int ny=dy[k]+itr.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                        flag=1;
                    }
                }
            }
            if(flag)
            ans+=1;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1)
                  return -1;
            }
        }
        return ans;
    }
};
// T.C=o(n*m)
// S.C=O(n*m)
