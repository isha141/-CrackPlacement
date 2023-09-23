class Solution {
    private :
    int n;
    int solve(int node,vector<vector<int>>&stones,vector<int>&vis){
        int ans=0;
         vis[node]=1;
        for(int j=0;j<n;++j){
          if(vis[j]==0 && ((stones[node][0]==stones[j][0]) || (stones[node][1]==stones[j][1]))){
              ans+=solve(j,stones,vis)+1;
          }  
        }
        return ans;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
           n=stones.size();
         vector<int>vis(n,0);
         int ans=0;
         for(int i=0;i<n;++i){
             if(!vis[i]){
                 ans+=solve(i,stones,vis);
             }
         }
        return ans;
    }
};

// T.C=o(n)
// S.C=o(n)
