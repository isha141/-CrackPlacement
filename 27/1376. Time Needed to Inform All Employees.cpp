class Solution {
    private:
    int solve(int node,vector<pair<int,int>>adj[],vector<int>&vis,vector<int>&in){
        queue<pair<int,int>>q;
        q.push({node,0});
        int ans=0;
        while(!q.empty()){
            int t=q.size();
             bool flag=0;
              while(t--){
                auto itr=q.front();
                q.pop();
                   vis[itr.first]=1;
                 ans=max(ans,itr.second);
                bool flag=0;
              for(auto iit: adj[itr.first]){
                    int val=iit.first;
                    if(!vis[val]){
                        q.push({val,itr.second+in[itr.first]});
                        vis[val]=1;
                    }
                }
            }
        }
        return ans;
    }
public:
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& in) { 
         vector<pair<int,int>>adj[n];
         for(int i=0;i<n;++i){
             if(manager[i]!=-1){
                 adj[manager[i]].push_back({i,in[i]});
             }
         }  
          vector<int>vis(n,0);
         return solve(head,adj,vis,in);
    }
}; 

// T.C=o(V+E)
// S.C=o(V)
