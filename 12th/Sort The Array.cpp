private:
    void solve(vector<int>&arr,int place,int n){ 
          vector<int>ans(n,0);
          vector<int>freq(10,0);
        for(int i=0;i<n;++i){
               int temp=arr[i];
                freq[((temp/place)%10)]++;
            }
            for(int i=1;i<=9;++i){
                freq[i]+=freq[i-1];
            }
            for(int i=n-1;i>=0;--i){
                int rem=(arr[i]/place)%10;
                int val=freq[rem];
                ans[val-1]=arr[i];
                freq[rem]--;
            }
            arr=ans;
        return;
    }
    public:
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here 
      vector<int>ans(n,0);
      int maxi=0;
      for(auto itr: arr){
          maxi=max(maxi,itr);
      }
      string s=to_string(maxi);
      int t=s.size(); 
      int place=1;
       while(t--){
            solve(arr,place,n);
            place*=10;
       }
       return arr;
    } 
// T.C=O(nk)
// S.C=O(n+k)
