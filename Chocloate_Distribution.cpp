#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i) cin>>a[i];
  int ans=INT_MAX;
  int m; cin>>m;
  sort(a.begin(),a.end());
  for(int i=0;i+m-1<n;++i){
    ans=min(ans,a[i+m-1]-a[i]);
  }
  cout<<ans<<endl;
  return 0;
}
// T.C=O(n)
// S.C=O(1)
