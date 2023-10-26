#include<bits/stdc++.h>
int solve(vector<int>&nums,int n){
        stack<int>s;
        vector<int>left(n,0);
		vector<int>right(n,0);
		for(int i=0;i<n;++i){
			while(!s.empty() && nums[s.top()]>=nums[i])
			s.pop();
			if(s.size()){
				left[i]=s.top()+1;
			}
			else{
				left[i]=0;
			}
			s.push(i);
		}

		while(!s.empty()) s.pop();
		for(int i=n-1;i>=0;--i){
			 while(!s.empty() && nums[s.top()]>=nums[i])
			 s.pop();
			if(s.size())
			right[i]=s.top()-1;
			else
			right[i]=n-1;
			s.push(i);
		}
		int ans=0;
		for(int i=0;i<n;++i){
			int width=(right[i]-left[i]+1);
			ans=max(ans,width*nums[i]);
		}
		return ans;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int>nums(m,0);
	int ans=0;
	for(int i=0;i<m;++i){
		nums[i]=mat[0][i];
	}
	ans=max(ans,solve(nums,m));
	for(int i=1;i<n;++i){
                for (int j = 0; j < m; ++j) { 
				if(mat[i][j])
                  nums[j] += mat[i][j];
				else
				nums[j]=0;
                }
			ans=max(ans,solve(nums,m));
    }
	return ans;
}
