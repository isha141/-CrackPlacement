class Solution{ 
    private:  
    int n;
    bool ok(int color,int node,bool graph[101][101],vector<int>&col){
        for(int i=0;i<n;++i){
            if(graph[i][node] && col[i]==color)
              return 0;
        }
        return 1;
    }
    int solve(int node,int m,bool graph[101][101],vector<int>&col){
        if(node>=n)
         return 1;
        for(int i=1;i<=m;++i){
            if(ok(i,node,graph,col)){
                col[node]=i;
                if(solve(node+1,m,graph,col))
                  return 1;
                col[node]=0;
            }
        }
        return 0;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        this->n=n;
        vector<int>col(n,0);
        return solve(0,m,graph,col);
    }
};  
// T.C=o(M^n)
// S.C=o(n)
