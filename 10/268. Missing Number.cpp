class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
        int total=(n*(n+1))/2;
        int sum=0;
        for(auto itr: nums) sum+=itr;
        return total-sum;
    }
};
// T.c=o(n)
// S.c=o(1)
