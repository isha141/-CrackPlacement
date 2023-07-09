class Solution { 
    int solve(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) 
                return 0;
            i++;
            j--;
        }
        return 1;
    }
public:
    bool validPalindrome(string s) {
        int n=s.size(); 
        int temp=solve(s);
        if(temp){
            return 1;
        }
        for(char ch='a';ch<='z';++ch){
            int count=0;
            int i=0;
            int j=n-1;
            while(i<j){
                if(s[i]!=s[j]){
                    if(s[i]==ch){
                        i++;
                    }
                    else{
                        j--;
                    }
                    count+=1;
                }
                else{
                    i++;
                    j--;
                }
            }
            if(count==1)
                 return 1; 
        }
        return  0;
    }
};  
// T.C=O(n)
// S.C=O(1)
