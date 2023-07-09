class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
         int n=h.size(); 
         int ans=0;
          int left[n];
          int right[n];
          stack<int>s;
          for(int i=0;i<n;++i){
              while(!s.empty() && h[s.top()]>=h[i]){
                  s.pop();
              }
              if(s.empty()){
                  left[i]=0;
              }
              else{
                  left[i]=s.top()+1;
              } 
              s.push(i);
          }
        while(!s.empty()) s.pop();
         for(int i=n-1;i>=0;--i){
              while(!s.empty() && h[s.top()]>=h[i]){
                  s.pop();
              }
              if(s.empty())
                    right[i]=n-1; 
              else 
                  right[i]=s.top()-1; 
             s.push(i);
         }
        for(int i=0;i<n;++i){
            ans=max(ans,h[i]*(right[i]-left[i]+1));
        }
         return ans;
    }
}; 
// T.c=O(n)+O(n)
// S.c=O(1)
