class Solution { 
    private:
     int n,m;
     bool ok(int i,int j,vector<vector<char>>&b,string &word,int k){ 
         if(k>=word.size()) return 1;
         if(i<0 || j<0 || i>=n || j>=m  || b[i][j]!=word[k])
               return 0; 
         
         // char ch=b[i][j];
         b[i][j]='.';
         int left=ok(i+1,j,b,word,k+1);
         int right=ok(i,j+1,b,word,k+1);
         int up=ok(i,j-1,b,word,k+1);
         int down=ok(i-1,j,b,word,k+1); 
         b[i][j]=word[k];
         return (left | right | up | down);
         
     }
public:
    bool exist(vector<vector<char>>& b, string word) {
           n=b.size();
           m=b[0].size();
          for(int i=0;i<n;++i){
              for(int j=0;j<m;++j){
                  if(word[0]==b[i][j] && ok(i,j,b,word,0) ){
                      return 1;
                  }
              }
          }
        return 0;
    } 
};
// T.C=O(n*m) * O(n+m)
// S.C=o(1)
