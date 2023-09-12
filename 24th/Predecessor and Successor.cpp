 private:
      void solve(Node *root,Node *&pre,Node *&suc,int key){
            while(root!=NULL){
            if(root->key==key){
                Node *temp=root->left;
                if(temp!=NULL){
                while(temp && temp->right!=NULL){
                    temp=temp->right;
                }
                pre=temp;
                }
                temp=root->right;
                if(temp!=NULL){
                while(temp && temp->left!=NULL){
                    temp=temp->left;
                }
                suc=temp;
                }
                return ;
            }
            else if(root->key<key){ 
                  pre=root;
                  root=root->right;
            }
            else{
                suc=root;
                root=root->left;
            }
        }
      }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(root==NULL)
          return ;
        solve(root,pre,suc,key);
    }
// T.C=o(n)
// S.C=O(1)
