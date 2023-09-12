/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution { 
    private:
    TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q){
          if(root==NULL)
                return root;
           TreeNode *left=NULL;
          TreeNode *right=NULL;
          if(root->val>p->val && root->val>q->val){
               // cout<<"hy"<<endl;
               left=solve(root->left,p,q);
          }
           if(root->val<p->val && root->val<q->val){
                 // cout<<"jjud"<<endl;
                right=solve(root->right,p,q);
          }
          if(left!=NULL)
                return left;
          if(right!=NULL)
                return right;
              return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         return solve(root,p,q);
    }
};
// T.C=O(h) where h is the height of the binary tree 
// S.C=O(1)
