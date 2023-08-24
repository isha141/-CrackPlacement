class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // if(head==NULL)
        //   return head;
        Node *zero=new Node(0);
        Node *one= new Node(0);
        Node *two= new Node(0);
        Node *prevzero=zero;
        Node *prevone=one;
        Node *prevtwo=two;
        while(head!=NULL){
            if(head->data==0){
                prevzero->next=head;
                prevzero=head;
            }
            else if(head->data==1){
                prevone->next=head;
                prevone=head;
            }
            else if(head->data==2){
                prevtwo->next=head;
                prevtwo=head;
            }
            head=head->next;
        }
        prevzero->next=one->next?one->next:two->next;
        prevone->next=two->next;
        prevtwo->next=NULL;
        return zero->next;
    }
}; 
// T.C=O(n)
// S.C=O(1)
