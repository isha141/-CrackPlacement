class Solution{
    int ans=0;
    void solve(Node *root,int k,map<int,int>&mp,int sum){
        if(mp.find(sum-k)!=mp.end()){
            ans+=mp[sum-k];
        }
        if(root==NULL)
          return ;
        mp[sum]++;
        solve(root->left,k,mp,sum+root->data); 
        solve(root->right,k,mp,sum+root->data);
        mp[sum]--;

    }
  public:
    int sumK(Node *root,int k)
    {
        if(root==NULL)
          return 0;
        map<int,int>mp;
        // mp[0]++;
        solve(root,k,mp,0);
        return ans/2;
    }
};

// T.C=o(n)
// S.C=o(1)
