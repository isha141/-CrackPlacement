class Solution { 
    private:
    int n;
public:
    string reverseWords(string s) {
        n=s.size();
         string ans="";
         string temp="";
         for(int i=0;i<n;++i){
             if(s[i]==' '){ 
                  while(i<n && s[i]==' '){
                      i++;
                  } 
                 if(temp.size())
                 ans=temp+" "+ ans; 
                 temp="";
                 if(i<n){   temp+=s[i];
                 }
             }
             else{
                 temp+=s[i];
             }
         } 
        if(temp.size()){
            ans=temp+" "+ans;
        }
        ans.pop_back();
         return ans;
    }
};
// T.c=O(n)
// S.c=O(1)
