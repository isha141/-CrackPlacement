#include <bits/stdc++.h> 
long long c=0;
long long merge(int low,int mid,int high,long long *arr,vector<long long>&temp){
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            c+=(mid-i+1);
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(int i=low;i<=high;++i){
        arr[i]=temp[i];
    }
    return c;
}
void solve(int low,int high,long long *arr,vector<long long>&temp){
    if(low<high){
        int mid=(low+high)>>1;
        solve(low,mid,arr,temp);
        solve(mid+1,high,arr,temp);
        merge(low,mid,high,arr,temp);
    }
    return ;
}
long long getInversions(long long *arr, int n){
    long low=0;
    long high=n-1;
    vector<long long>temp(n,0);
     solve(low,high,arr,temp);
    return c;
}

// T.C=o(nlogn)
// S.C=o(n)
