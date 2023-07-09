class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
         string ans="";
         string temp=strs[0];
         for(int i=0;i<temp.size();++i){
             ans+=temp[i];
             for(int j=0;j<n;++j){
                 string temp=strs[j].substr(0,ans.size()); 
                 // cout<<temp<<";;"<<ans<<endl;
                 if(temp!=ans){
                       ans.pop_back();
                      return ans;
                 }
             }
         }
        return ans;
    }
}; 

// T.c=O(n2)
// S.c=O(1)
