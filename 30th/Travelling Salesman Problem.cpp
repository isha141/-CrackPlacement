int dp[20][(1<<20)+1];
class Solution {
    private:
    int n;
    bool ok(int mask){
        // for(int i=0;i<n;++i){
        //     if((mask & (1<<i))==0)
        //     return 0;
        // }
        // return 1;
    }
    int solve(int node,int mask,vector<vector<int>>&cost){
        if(mask==((1<<n)-1)){
            return cost[node][0];
        }
        if(dp[node][mask]!=-1)
          return dp[node][mask];
        int ans=INT_MAX;
        for(int j=0;j<n;++j){
            if((mask&(1<<j))==0 && node!=j){
                ans=min(ans,cost[node][j]+solve(j,(mask|(1<<j)),cost));
            }
        }
        return dp[node][mask]=ans;
    }
public:
int total_cost(vector<vector<int>>cost){
    // Code here
     n=cost.size();
    memset(dp,-1,sizeof(dp));
    vector<int>vis(n,0);
    int mask=0;
    return solve(0,1,cost);
} 

// T.C=o(2^n)+o(n^2)
// S.C=o(2^n+n)
