class StockSpanner { 
    stack<pair<int,int>>s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.size()){
            int ans=0;
            while(!s.empty() && s.top().first<=price){
                ans+=s.top().second;
                s.pop();
            }
            ans+=1;
            s.push({price,ans});
            return ans;
        }
        else{
            s.push({price,1});
            return 1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// T.C=O(n)
// S.C=O(n)
