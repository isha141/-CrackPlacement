int dp[45][45];
class Solution {
private:
    int solve(vector<int>&arr,map<pair<int,int>,int>&mp,int left,int right){
        if(left==right)
             return 0;
        int ans=INT_MAX;
        if(dp[left][right]!=-1)
              return dp[left][right];
        for(int k=left;k<right;++k){
            ans=min(ans,mp[{left,k}]*mp[{k+1,right}]+ solve(arr,mp,left,k)+ solve(arr,mp,k+1,right));
        }
        return dp[left][right]=ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int>mp;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i){
            mp[{i,i}]=arr[i];
            for(int j=i+1;j<n;++j){
                mp[{i,j}]=max(mp[{i,j-1}],arr[j]);
            }
        }
        return solve(arr,mp,0,n-1);
    }
};

// T.C=O(n*n)
// S.C=O(n*n)
