class Solution{
    private:
    map<int,int>mp;
    Node *solve(int prestart,int preend,int pre[],int instart,int inend,int in[]){
        if(prestart>preend || instart>inend)
          return NULL;
        Node *root=new Node();
        root->data=pre[prestart];
        int inroot=mp[pre[prestart]];
        int numsleft=inroot-instart;
        root->left=solve(prestart+1,prestart+numsleft,pre,instart,inroot-1,in);
        root->right=solve(prestart+numsleft+1,preend,pre,inroot+1,inend,in);
        return root;
    }
public:
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    { 
        int in[size+1];
        for(int i=0;i<size;++i){
            in[i]=pre[i];
        }
        sort(in,in+size);
        for(int i=0;i<size;++i){
            mp[in[i]]=i;
        }
        return solve(0,size-1,pre,0,size-1,in);
        
    }
};
// T.C=o(nlogn)
// S.C=O(1)
