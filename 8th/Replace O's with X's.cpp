int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void solve(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || mat[i][j]=='X'){
            return ;
        } 
        vis[i][j]=1;
        // mat[i][j]='X';
        for(int k=0;k<4;++k){
            int nx=dx[k]+i;
            int ny=dy[k]+j; 
             solve(nx,ny,mat,vis);
        }
        
        return;
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        this->n=n;
        this->m=m;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;++i){
           if(mat[n-1][i]=='O'){
               solve(n-1,i,mat,vis);
           }
           if(mat[0][i]=='O'){
               solve(0,i,mat,vis);
           }
        }
        for(int i=0;i<n;++i){
            if(mat[i][0]=='O'){
                solve(i,0,mat,vis);
            }
            if(mat[i][m-1]=='O'){
                solve(i,m-1,mat,vis);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
    }

// T.C=o(n*m)
// S.C=O(n*m)
