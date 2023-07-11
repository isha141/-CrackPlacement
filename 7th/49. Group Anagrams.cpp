class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
          int n=strs.size(); 
          map<string,vector<string>>mp;
          for(auto itr: strs){
              string temp=itr;
              sort(temp.begin(),temp.end());
              mp[temp].push_back(itr);
          }
          for(auto itr: mp){
              vector<string>ds=itr.second;
              ans.push_back(ds);
          }
         return ans;
    }
};

// T.c=O(nlogn)
// S.c=O(n)
