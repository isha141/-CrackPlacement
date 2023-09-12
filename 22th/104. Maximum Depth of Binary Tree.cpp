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
    int ans=0;
    int solve(TreeNode *root){
        if(root==NULL)
              return 0;
        int l=solve(root->left);
        int r=solve(root->right);
         ans=max(ans,l+r);
        return max(l,r)+1;
    }
public:
    int maxDepth(TreeNode* root) {
          if(root==NULL)
                return 0;
        return solve(root);
         // return ans;
    }
};
// T.C=o(n)
// S.C=o(1)
