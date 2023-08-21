class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
         while(low<=high){
             int mid=(low+high)>>1;
             if(nums[mid]==target)
                   return mid;
             if(nums[low]<=nums[mid]){
                 if(target>=nums[low] && target<nums[mid]){
                     high=mid-1;
                 }
                 else{
                     low=mid+1;
                 }
             }
             else{
                 if(nums[mid]<target && nums[high]>=target){
                     low=mid+1;
                 }
                 else{
                     high=mid-1;
                 }
             }
         }
         return -1;
    }
}; 
// T.C=O(logn)
// S.C=O(1)
