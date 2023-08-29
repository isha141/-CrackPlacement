class Solution{
    Node *solve(Node *head){
        Node *slow=head;
        Node *fast=head;
        while(slow && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *left, Node *right,Node *middle){
        Node *dummy=new Node(0);
        Node *curr=dummy;
        while(left!=NULL && middle!=NULL){
            if(left->data<middle->data){
                curr->next=left;
                left=left->next;
                curr=curr->next;
            }
            else{
                curr->next=middle;
                curr=curr->next;
                middle=middle->next;
            }
        }
        if(left){
            curr->next=left;
        }
        else{
            curr->next=middle;
        }
        return dummy->next;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
          return head;
        Node *left=head;
        Node *middle=solve(head);
        Node *right=middle->next;
        middle->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        head=merge(left,middle,right);
        return head;
    }
}; 
// T.C=O(nlogn)
// S.C=O(1)
