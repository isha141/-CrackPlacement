class Solution
{
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
        if(head==NULL) 
          return head; 
        Node *root=head;
        int count=0;
        while(head!=NULL){
            count+=1;
            if(count%2 && head->next && head->data>head->next->data){
                swap(head->data,head->next->data);
            }
            else if(count%2==0 && head->next && head->data<head->next->data){
                swap(head->data,head->next->data);
            }
            head=head->next;
        }
        return root;
    }
};

// T.C=O(n)
// S.C=O(1)
