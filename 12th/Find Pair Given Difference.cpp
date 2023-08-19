bool findPair(int arr[], int size, int n){
    //code
    int i=0;
    int j=1;
    sort(arr,arr+size);
    while(i<size && j<size){
        if(i!=j && arr[j]-arr[i]==n){
            return 1;
        }
       else if((arr[j]-arr[i])<n){
            j++;
        }
        else{
            i++;
        }
    }
    return 0;
    
}

// T.C=O(nlogn)
// S.C=O(1)
