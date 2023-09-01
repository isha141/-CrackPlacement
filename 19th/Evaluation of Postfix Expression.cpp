int evaluatePostfix(string st)
    {
        // Your code here
        stack<int>s;
        for(auto itr: st){
            if(isdigit(itr)){
                s.push(itr-'0');
            }
            else if(itr=='+'){
                int temp=s.top();
                s.pop();
                int temp2=s.top();
                s.pop();
                s.push(temp+temp2);
            }
            else if(itr=='-'){
                int temp=s.top();
                s.pop();
                int temp2=s.top();
                s.pop();
                s.push(temp2-temp); 
            }
            else if(itr=='*'){
                int temp=s.top();
                s.pop();
                int temp2=s.top();
                s.pop();
                s.push(temp*temp2);
            }
            else {
                int temp=s.top();
                s.pop();
                int temp2=s.top();
                s.pop();
                if(temp==0)
                s.push(0);
                else
                s.push(temp2/temp);
            }
        }
        return s.top();
    }
// T.C=O(n)
// S.C=O(n)
