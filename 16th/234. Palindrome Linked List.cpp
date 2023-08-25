/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution { 
    private:
    ListNode *prev=NULL;
    ListNode *reverse(ListNode *head){
            if(head==NULL || head->next==NULL){
                prev=head;
                return prev;
            }
        ListNode *p=reverse(head->next);
        p->next=head;
        head->next=NULL;
        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
          if(head==NULL) return 1;
          ListNode *slow=head;
          ListNode *fast=head;
          while(fast && fast->next && fast->next->next){
              slow=slow->next;
              fast=fast->next->next;
          }
          reverse(slow->next); 
           if(prev){
               // cout<<prev->val<<";;"<<endl;
           }
           while(prev!=NULL){
               if(head->val!=prev->val)
                   return 0;
               prev=prev->next;
               head=head->next;
           }
          return 1;
    }
}; 
// T.C=O(n)
// S.C=O(1)
