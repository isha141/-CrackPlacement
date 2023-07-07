class Solution { 
    private:
    int n;
public:
    bool canJump(vector<int>& nums) {
          n=nums.size();
         int ans=0;
         for(int i=0;i<n;++i){
             if(ans<i) return 0;
             ans=max(ans,i+nums[i]);
             if(ans>=n-1) return 1;
         }
        return 0;
    }
}; 

// T.C=O(n)
// S.c=O(1)
