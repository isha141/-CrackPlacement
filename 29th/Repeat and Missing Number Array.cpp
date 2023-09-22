vector<int> Solution::repeatedNumber(const vector<int> &a) { 
      int n=a.size();
      vector<int>res;
      int rep=-1;
      int miss=-1;
      long long squareSum=0;
      long long sum=0;
     for(auto it: a){
         squareSum=squareSum+(1ll*it*it);
         sum+=it;
     }
    //   long long sum=accumulate(a.begin(),a.end(),0);
      long long nthsum=(1ll*n*(n+1))/2;
      long long rem=sum-nthsum;   // eq1 (1)
    //   A=[1,3,5,5,6,4]     rep==5, missing,2;
    //   int sum=(5)-  +2) == (rep-missing)== 3 
    //  long long squareSum=0;
    // for(auto it: a){
    //      squareSum=squareSum+(it*it);
    // }
     long long nthSquareSum=(1ll*n*(n+1)*(2*n+1))/6;
     long long remSum=squareSum-nthSquareSum;
     remSum/=rem;
     long long val1=((long long)remSum+(long long)rem)/2;
     long long val2=val1-rem;
     return {val1,val2};
}

// T.C=o(n)
// S.C=o(1)
