class Solution {
public:
    int maximumProduct(vector<int>& nums) {
          long  ans=INT_MIN;
          int n=nums.size(); 
         sort(nums.begin(),nums.end());
         ans=max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
        return ans;
    }
}; 

// T.c=O(nlongn)
// S.c=o(1)
