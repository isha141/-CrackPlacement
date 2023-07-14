 private:
    int n,m;
    int solve(vector<int>&height){
        stack<int>s;
        vector<int>left(m,0);
        vector<int>right(m,0);
        int i=0;
        while(i<m){
            while(!s.empty() && height[s.top()]>=height[i]) s.pop();
            if(s.empty()){
                left[i]=0;
            }
            else{
                left[i]=s.top()+1;
            }
            s.push(i); 
            i++;
        }
        while(!s.empty()) s.pop();
        i=m-1;
        while(i>=0){
            while(!s.empty() && height[s.top()]>=height[i]) s.pop();
            if(s.empty()){
                right[i]=m-1;
            }
            else{
                right[i]=s.top()-1;
            }
            s.push(i);
            i--;
        }
        int ans=0;
        for(int i=0;i<m;++i){
            ans=max(ans,(right[i]-left[i]+1)*height[i]);
        }
        return ans;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here  
        this->n=n;
        this->m=m;
        vector<int>height(m,0); 
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(M[i][j]){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            } 
            ans=max(ans,solve(height));
        }
        return ans;
    } 

// T.C=O(n*m)
// S.C=O(m)
