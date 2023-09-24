class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here 
        vector<pair<int,int>>mst;
        vector<int>vis(V,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,-1}});
        int ans=0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int node=itr.second.first;
            int parent=itr.second.second;
            int weight=itr.first;
            if(vis[node]==1)
              continue;
            if(!vis[node] && parent!=-1){
                mst.push_back({node,parent});
                ans+=weight;
            }
            vis[node]=1;
            for(auto iit: adj[node]){
                int n=iit[0];
                if(!vis[n]){
                    pq.push({iit[1],{n,node}});
                }
            }
        }
        return ans;
    }
};


// T.C=o(ElogV)
// S.C=o(V)
