class Solution{
    private:
    map<Node*,Node*>mp;
    Node *head=NULL;
    void findparent(Node *root,int a){
        if(root==NULL)
          return;
        if(root->data==a){
            head=root;
        }
        if(root->left==NULL && root->right==NULL)
          return ;
        findparent(root->left,a);
        if(root && root->left){
            mp[root->left]=root;
        }
        if(root->right){
            mp[root->right]=root;
        }
        findparent(root->right,a);
    }
    public:
    int findDist(Node* root, int a, int b) {
        // Your code here
        queue<pair<Node*,int>>q;
        int ans=INT_MAX;
        findparent(root,a);
        q.push({head,0});
        map<Node*,int>dis;
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            Node* root=itr.first;
            int c=itr.second;
            if(root->data==b){
                ans=min(ans,itr.second);
            }
            if(root->left && dis.find(root->left)==dis.end()){
                dis[root->left]=c+1;
                q.push({root->left,c+1});
            }
            else if(dis[root->left]>c+1){
                dis[root->left]=c+1;
                q.push({root->left,c+1});
            }
            if(root->right && dis.find(root->right)==dis.end()){
                dis[root->right]=c+1;
                q.push({root->right,c+1});
            }
            else if(dis[root->right]>c+1){
                dis[root->right]=c+1;
                q.push({root,c+1});
            }
            if(mp.find(root)!=mp.end() && dis.find(mp[root])==dis.end()){
                   q.push({mp[root],c+1});
                   dis[mp[root]]=c+1;
            }
            else if(mp.find(root)!=mp.end() && dis[mp[root]]>c+1){
                   q.push({mp[root],c+1});
                   dis[mp[root]]=c+1;
            }
        }
    return ans;
    }
// T.C=O(n)
// S.C=O(n)
