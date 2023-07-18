class Solution {
public:
    bool isPalindrome(int x) { 
        long rem=0; 
        long num1=0;
        long temp=x; 
        if(x==0)
        {  
            return 1;
        } 
        if(x>0) 
        { 
        while(x!=0)
        {
            rem=x%10; 
            num1=num1*10+rem;
            x=x/10;
        } 
        if(temp==num1)
        {
            return 1;
        }  
        }
        return 0;
    }
};
// T.c=O(n)
// S.c=o(1)
