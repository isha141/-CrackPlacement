
class Solution {
    private: 
    int n; 
    int count(int low,int mid,int high,vector<int>&nums){
        int res=0;
        int j=mid+1;
        while(low<=mid){
             while(j<=high && nums[low]>2*1ll*nums[j]){
                 j++;
             }
            low++;
            res+=(j-mid-1);
        }
        return res;
    }
    int ok(int low,int mid,int high,vector<int>&nums){
        int i=low;
        int j=mid+1;  
        int temp=0;
        int ds[n]; 
        int k=low; 
        temp=count(low,mid,high,nums);
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                ds[k++]=nums[i++];
            }
            else{
                ds[k++]=nums[j++];
            }
        }
        while(i<=mid){
           ds[k++]=nums[i++];
        }
        while(j<=high){
            ds[k++]=nums[j++];
        }
        for(int i=low;i<=high;++i){
            nums[i]=ds[i];
        }
        // count+=temp;
        return temp;
    }
    int solve(int low,int high,vector<int>&nums){ 
         int temp=0;
        if(low<high){
            int mid=(low+high)/2;
            temp+=solve(low,mid,nums);
            temp+=solve(mid+1,high,nums);
            temp+=ok(low,mid,high,nums);
        }
        return temp;
    }
public:
    int reversePairs(vector<int>& nums) {
           n=nums.size(); 
          // vector<int>ds;
         int count=0;
        return  solve(0,n-1,nums); 
        // return count;
    }
}; 
//T.C=O(nlong)
// S.C=O(n)
