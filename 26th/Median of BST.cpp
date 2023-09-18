int solve(struct Node *root){
    if(root==NULL)
      return 0;
    int l=solve(root->left);
    int r=solve(root->right);
    return (l+r)+1;
}
pair<int,int> ok(Node *root,int count){
    int m1=0;
    int m2=0;
    int i=0;
    while(root!=NULL){
        //  cout<<i<<";;"<<endl;
        if(root->left==NULL){
            i+=1;
            if(i==count){
                m1=root->data;
            }
            if(i==count+1){
                m2=root->data;
            }
            root=root->right;
        }
        else{
            Node *curr=root->left;
            while(curr->right!=NULL && curr->right!=root){
                curr=curr->right;
            }
            if(curr->right==NULL){
                curr->right=root;
                root=root->left;
            }
            else{
                i+=1;
                if(i==count){
                    m1=root->data;
                }
               if(i==count+1){
                  m2=root->data;
                }
                root=root->right;
                curr->right=NULL;
            }
        }
    }
    return {m1,m2};
}
float findMedian(struct Node *root)
{
      //Code here
      int cnt=solve(root);
      pair<int,int>itt;
      itt=ok(root,cnt/2);
    //   cout<<itt.first<<";;"<<itt.second<<endl;
      if(cnt%2){
          return (double)itt.second;
      }
      else{
          return (double)(itt.first+itt.second)/2.0;
      }
}

// T.C=o(n)
// S.C=o(1)
