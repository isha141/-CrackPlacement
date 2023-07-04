class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
         int n=mat.size();
         int m=mat[0].size();
         bool col=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;++j){
                 if(mat[i][j]==0){
                     mat[i][0]=0;
                     if(j!=0){
                         mat[0][j]=0;
                     }
                     else{
                         col=1;
                     }
                 }
             }
         }
         for(int i=1;i<n;++i){
             for(int j=1;j<m;++j){
                 if(mat[i][j]!=0){
                     if(mat[i][0]==0 || mat[0][j]==0){
                         mat[i][j]=0;
                     }
                 }
             }
         }
        if(mat[0][0]==0){
            for(int i=0;i<m;++i){
                mat[0][i]=0;
            }
        }
        if(col){
            for(int j=0;j<n;++j){
                mat[j][0]=0;
            }
        }
        return ;
    }
}; 
// step1-> mark the 0 row and 0th column if (mat[i][j]==0)
//     since the first cell is sharing in both rows and column for this use extra col variable which keep track of the column  
// Step2-> Iterating over the 1th row and 1th col if mat[i][0]==0 || mnat[0][j]==0  then set mat[i][j]=0;
// step 3-> if(mat[0][0]==0) then set the 0th row with the 0 
// step 4-> if(col==1) then set the whole column with 0 
// T.C=o(N*m)
// S.C=o(1)
