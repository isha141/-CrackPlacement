class Solution {
private:
    void solve(string src,string &des,map<string,vector<pair<string,double>>>&mp,unordered_set<string>&s,double ans,double &pro){
        if(s.find(src)!=s.end()){
             return;
        }
        s.insert(src);
        if(src==des){
            pro=ans;
             return;
        }
        for(auto itt: mp[src]){
            if(s.find(itt.first)==s.end()){
                solve(itt.first,des,mp,s,ans*itt.second,pro);
            }
        }
        return ;
    }
public:
    vector<double> calcEquation(vector<vector<string>>&eq, vector<double>& val, vector<vector<string>>& qu) {
        vector<double>ans;
        int n=eq.size();
        map<string,vector<pair<string,double>>>mp;
        for(auto i=0;i<n;++i){
            string a=eq[i][0];
            string b=eq[i][1];
            double value=val[i];
            mp[a].push_back({b,value});
            mp[b].push_back({a,1.0/value});
        }
        for(auto itr:qu){
            string src=itr[0];
            string des=itr[1];
            if(mp.find(src)==mp.end() || mp.find(des)==mp.end()){
                ans.push_back(-1.0000);
                continue;
            }
             double ans1=1.0000;
             double pro=-1.0000;
            unordered_set<string>s;
            solve(src,des,mp,s,ans1,pro);
                ans.push_back(pro);
        }
        return ans;
    }
};
// T.C=o(n*E)
// S.C=o(E)
