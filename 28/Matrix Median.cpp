int ok(int mid,vector<vector<int>>&a){
    int n=a.size();
    int m=a[0].size();
    int count=0;
    for(int i=0;i<n;++i){
        int j=0;
        while(j<m && a[i][j]<=mid){
             j++;
        }
        count+=(j);
    }
     return count;
}

int Solution::findMedian(vector<vector<int> > &A) {
     int low=1;
     int high=1e9;
     int n=A.size();
     int m=A[0].size();
     int median=(n*m)/2;
     while(low<=high){
         int mid=(low+high)>>1;
         if(ok(mid,A)<=median){
             low=mid+1;
         }
         else{
             high=mid-1;
         }
     }
     return low;
}
// T.C=o(log2(2^32)) *o(n*m)
// S.C=o(1)
