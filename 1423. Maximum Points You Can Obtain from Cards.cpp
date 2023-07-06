class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int ans=0;
        vector<int>pre(n,0),suff(n,0);
         pre[0]=card[0];
        for(int i=1;i<n;++i){
            pre[i]=pre[i-1]+card[i];
        }
          suff[n-1]=card[n-1];
        for(int i=n-2;i>=0;--i){
            suff[i]=suff[i+1]+card[i];
        }
        reverse(suff.begin(),suff.end());
         for(int i=0;i<k-1;++i){
             ans=max(ans,pre[i]+suff[k-i-2]);
         }
        ans=max(ans,pre[k-1]);
        ans=max(ans,suff[k-1]);
        return ans;
    }
};

// T.C=O(n)
// S.c=o(n)
