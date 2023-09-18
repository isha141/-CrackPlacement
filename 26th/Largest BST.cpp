class info{
    public:
    int mini;
    int maxi;
    int size;
    info(int mini,int maxi,int size){
        this->mini=mini;
        this->maxi=maxi;
        this->size=size;
    }
};
class Solution{
    private:
    info solve(Node *root){
        if(root==NULL)
         return {INT_MAX,INT_MIN,0};
        if(root->left==NULL && root->right==NULL){
            return {root->data,root->data,1};
        }
        auto l=solve(root->left);
        auto r=solve(root->right);
        if(root->data>l.maxi && root->data<r.mini){
            return {min(l.mini,root->data),max(root->data,r.maxi),l.size+r.size+1};
        }
        
        else{
           return {INT_MIN,INT_MAX,max(l.size,r.size)};
        }
    }
    public:
    int largestBst(Node *root)
    {
        if(root==NULL)
          return 0;
        return solve(root).size;
    }
}; 

// T.C=o(n)
// S.C=o(1)
