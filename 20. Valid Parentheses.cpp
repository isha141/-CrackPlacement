class Solution {
public:
    bool isValid(string st) {
         stack<char>s;
         for(auto itr: st){
             if(itr==')' || itr=='}' || itr==']'){
                 if(!s.empty() && s.top()=='(' && itr==')'){
                       s.pop();
                 }
                 else if(!s.empty() && s.top()=='{' && itr=='}'){
                       s.pop();
                 }
                 else if(!s.empty() && s.top()=='[' && itr==']'){
                       s.pop();
                 } 
                 else 
                     return 0;
             }
             else{
                 s.push(itr);
             }
         }
        if(s.size())
             return 0;
        return 1;
    }
}; 


// T.C=O(n)
// S.c=o(1)
