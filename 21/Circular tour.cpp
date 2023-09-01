class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here 
       int dis=0;
       for(int i=0;i<n;++i){
           dis+=p[i].petrol-p[i].distance;
        }
        if(dis<0)
        return -1;
       int start=0;
       int i=0;
       int petrol=0;
       while(i<n){
            petrol+=p[i].petrol-p[i].distance;
           if(petrol<0){
               start=(i+1);
               petrol=0;
               i+=1;
           }
           else
           i=(i+1);
       }
        return start==n?-1:start;
    }
};
// T.C=o(n)
// S.C=O(1)
