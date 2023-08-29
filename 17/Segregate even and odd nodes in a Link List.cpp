
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *dummye=new Node(0);
        Node *even=dummye;
        Node *dummyo=new Node(0);
        Node *odd=dummyo;
        while(head!=NULL){
            if(head->data%2==0){
                even->next=head;
                even=even->next;
            }
            else{
                odd->next=head;
                odd=odd->next;
            }
            head=head->next;
        }
        even->next=NULL;
        odd->next=NULL;
        even->next=dummyo->next;
        return dummye->next;
    }
};

// T.C=O(n)
// S.C=O(1)
