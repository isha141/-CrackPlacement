class Solution {
public:
    int minMoves(vector<int>& nums) {
          int n=nums.size();
          int maxi=0;
          int mini=INT_MAX; 
        long ans=0;
          for(auto itr: nums){
              maxi=max(maxi,itr);
              mini=min(mini,itr);
          }
          for(auto itr: nums){
              ans+=abs(itr-mini);
          } 
        return ans;
    }
};
// T.c=O(n)


// Approach  --> By reversing the prblem decreamenting 1 from all the elemnets until all the element is not equal to minimul
