class Solution {
public:
    int maxArea(vector<int>& height) {
          int n=height.size();
        int ans=0;
         int low=0;
         int high=n-1;
        while(low<high){ 
             int width=(high-low);
                ans=max(ans,width*(min(height[low],height[high])));
            if(height[low]<height[high]){
                 low++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};

// T.c=O(n)
// S.c=O(1)
