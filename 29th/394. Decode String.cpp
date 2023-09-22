class Solution {
    private:
    string repeat(string &a,int n){
        string ans="";
        for(int i=0;i<n;++i){
            ans+=a;
        }
        return ans;
    }
public:
    string decodeString(string s) {
          int n=s.size();
          stack<string>st;
          string curr="";
          int val=0;
          for(auto itr: s){
              if(itr=='['){
                  st.push(curr);
                  st.push(to_string(val));
                  val=0;
                  curr="";
              }
              else if(itr==']'){
                  auto iit=st.top();
                  st.pop();
                  int val=0;
                  for(auto a: iit){
                      val=val*10+a-'0';
                  }
                  string prev=st.top();
                  st.pop();
                  prev+=repeat(curr,val);
                  // st.push(prev);
                  curr=prev;
              }
              else if(isdigit(itr)){
                  val=val*10+itr-'0';
              }
              else{
                  curr+=itr;
              }
          }
        return curr;
    }
};
// T.C=o(n)
// S.C=o(n)
