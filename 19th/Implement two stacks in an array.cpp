class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    int curr1,curr2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
        curr1=-1;
        curr2=size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top1==-1){
            top1=0;
        }
            // curr1=0;
            arr[++curr1]=x;
        
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top2==size){
            top2=size-1;
        }
        arr[--curr2]=x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(curr1==-1)
          return curr1;
         return arr[curr1--];
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(curr2==size)
        return -1;
        return arr[curr2++];
    }
};
// T.C=O(1)
// S.C=O(n)
