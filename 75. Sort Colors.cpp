class Solution {
public:
    void sortColors(vector<int>& nums) {
         int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;  
                mid++;
            }
            else if(nums[mid]==1){
                mid+=1;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        return ;
    }
};
// T.C=o(n)
// S.C=o(1)
