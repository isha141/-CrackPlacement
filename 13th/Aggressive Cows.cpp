class Solution {
    private:
    bool ok(int mid,vector<int>&stalls,int n,int k){
        int c=1;
        int sum=stalls[0];
        for(int i=1;i<n;++i){
            if(stalls[i]-sum>=mid){
                sum=stalls[i];
                c+=1;
            }
        }
        if(c<k)
        return 0;
        return 1;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=0;
        int ans=0;
        int high=stalls[n-1];
        while(low<=high){
            int mid=(low+high)>>1;
            if(ok(mid,stalls,n,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
// T.C=O(nlogn)
// S.C=O(1)
