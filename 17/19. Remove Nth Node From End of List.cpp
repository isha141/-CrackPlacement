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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          if(head==NULL)
               return head;
          if(n==1){
              if(head->next==NULL)
                    return NULL;
          }
          ListNode *dummy=new ListNode(0);
           dummy->next=head;
          ListNode *slow=dummy;
          ListNode *fast=dummy;
          for(int i=1;i<=n;++i){
              fast=fast->next;
          }
          while(fast->next!=NULL){
               slow=slow->next;
               fast=fast->next;
          }
          slow->next=slow->next->next;
          return dummy->next;
    }
}; 
// T.C=O(n)
// S.C=O(1)
