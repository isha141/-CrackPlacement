/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
      vector<TreeNode*> solve(int l,int r){
           if(l>r){
                return{NULL};
           }
          vector<TreeNode*>ans;
          for(int i=l;i<=r;++i){
              vector<TreeNode *>lefti=solve(l,i-1);
              vector<TreeNode *>righti=solve(i+1,r);
              for(auto itt:lefti){
                  for(auto iit: righti){
                      TreeNode *root=new TreeNode(i);
                        root->left=itt;
                        root->right=iit;
                       ans.push_back(root);
                  }
              }
          }
          return ans;
      }
public:
    vector<TreeNode*> generateTrees(int n) {
         return solve(1,n);
          // return ans;
    }
};
// T.C=Exponential
// S.C=O(n)
