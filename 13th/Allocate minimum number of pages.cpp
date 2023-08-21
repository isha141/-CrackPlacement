class Solution 
{ 
    private:
    int solve(int mid,int a[],int n,int m){
        int sum=0; 
        int count=1;
        for(int i=0;i<n;++i){
            if(a[i]>mid)
             return 0;
           else if((sum+a[i])<=mid){
                sum+=a[i];
            }
            else if((sum+a[i])>mid){
                 sum=a[i];
                 count+=1;
            }
        }
        if(count>m)
          return 0;
        return 1;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        if(m>n){
            return -1;
        }
        // sort(a,a+n);
        int low=0;
        int high=0;
        for(int i=0;i<n;++i){
              high+=a[i];
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1;
            if(solve(mid,a,n,m)){
              ans=mid;
              high=mid-1;
            }
            else{
              low=mid+1;
            }
        }
        return ans;
    } 
// T.C=O(nlogn)
// S.C=O(1)
