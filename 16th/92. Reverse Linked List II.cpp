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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         int count=1;
         ListNode *dummy=new ListNode(0);
         dummy->next=head;
         ListNode *p=dummy;
         while(count<left){
             p=p->next;
             count+=1;
         }
         ListNode *tail=p->next;
         for(int i=0;i<right-left;++i){
             ListNode *temp=tail->next;
              tail->next=temp->next;
              temp->next=p->next;
               p->next=temp;
         }
          return dummy->next;
    }
};
// T.C=O(n)
// S.C=O(1)


/// Reversing a single loop 
