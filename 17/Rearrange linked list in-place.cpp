Node *solve(Node *root){
    if(root==NULL)
      return root;
    Node *slow=root;
    Node *fast=root;
    while(slow && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *reverse(Node *head){
    Node *temp=head->next;
    head->next=NULL;
    while(temp!=NULL){
        Node *p=temp->next;
        temp->next=head;
        head=temp;
        temp=p;
    }
    return head;
}
Node *inPlace(Node *root)
{
 // your code goes here 
        if(root==NULL)
        return root;
        Node *middle=solve(root);
        middle=middle->next;
        middle=reverse(middle);
        Node *head=root;
        while(middle!=NULL){
            Node *temp=middle->next;
            middle->next=head->next;
            head->next=middle;
            head=head->next->next;
            middle=temp;
        }
        head->next=NULL;
        return root;
}

// T.C=O(n)
// S.C=O(1)
