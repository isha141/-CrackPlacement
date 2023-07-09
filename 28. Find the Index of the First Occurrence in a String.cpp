class Solution {
public:
    int strStr(string stack, string need) {
          if(stack.find(need)==string::npos){
              return -1;
          }
          int temp=stack.find(need);
          return temp;
         
    }
};

// T.C=O(n)
// S.C=O(1)
