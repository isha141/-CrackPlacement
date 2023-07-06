class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> ans;
         int n=nums.size();
         sort(nums.begin(),nums.end());
         for(int i=0;i<n;++i){
             int sum=nums[i];
             int low=(i+1);
             int high=n-1;
             while(low<high){
                 if(nums[low]+nums[high]+sum==0){
                     ans.push_back({nums[i],nums[low],nums[high]});
                 }
                 int prev=low;
                 while(low<high && nums[low]==nums[prev]){
                     low++;
                 }
                 prev=high;
                 while(high>low && nums[prev]==nums[high]){
                     high--;
                 }
                 
             }
         }
        return ans;
    }
};
// T.c=O(n2)
// S.c=o(1)
