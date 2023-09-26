class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n)
         return kthElement(arr2,arr1,m,n,k);
        int low=max(0,k-m); /// if m has less number of elements then we have  to pick minimu of (k-m) 
        // elements from arr1
        int high=min(n,k);
        while(low<=high){
            int mid=(low+high)>>1;
            int mid2=(k-mid);
            int l1=mid==0?INT_MIN:arr1[mid-1];
            int l2=mid2==0?INT_MIN:arr2[mid2-1];
            int r1=mid==n?INT_MAX:arr1[mid];
            int r2=mid2==m?INT_MAX:arr2[mid2];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            if(l1>r2){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return 0;
    }
};

// T.C=O(log(n))
// S.C=o(1)
