class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
          int n=p.size();
          int ans=INT_MIN;
         priority_queue<pair<int,int>>pq;
          for(int i=0;i<n;++i){
              while(!pq.empty() && abs(pq.top().second-p[i][0])>k) 
                  pq.pop();
              if(!pq.empty()){
                  ans=max(ans,pq.top().first+p[i][0]+p[i][1]);
              }
              pq.push({p[i][1]-p[i][0],p[i][0]});
          }
         return ans;
    }
}; 

// T.c=O(n log(n))
// S.c=O(n)
