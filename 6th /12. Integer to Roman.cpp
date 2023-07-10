class Solution {
public:
    string intToRoman(int num) {
       vector<int>nums={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>ds{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n=nums.size();
        string ans="";
        for(int i=0;i<n;++i){
            while(num>=nums[i]){
                ans+=ds[i];
                num-=nums[i];
            }
        }
        return ans;
    }
};

// T.c=o(n)
// S.c=o(26)
