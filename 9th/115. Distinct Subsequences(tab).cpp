int numDistinct(string s, string t) {
          n=s.size();
          m=t.size();
          vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
          long ans=0; 
        for(int i=0;i<n;++i){
            dp[i][0]=1;
        }
          for(int i=1;i<=n;++i){
              for(int j=1;j<=m;++j){ 
                  int take=0;
                  int not_take=0;
                  if(s[i-1]==t[j-1]){
                     dp[i][j]=1ll*(1ll*dp[i-1][j-1]+1ll*dp[i-1][j])%mod;
                  }
                  else{
                      dp[i][j]=dp[i-1][j];
                  }
              }
          }
        return dp[n][m];
    }

// T.c=O(n*m)
// S.c-O(n*m)
