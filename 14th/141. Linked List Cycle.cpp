/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
           ListNode *slow=head;
           ListNode *fast=head;
          while(fast && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast)
                      return 1;
          }
          return 0;
    }
};

// T.C=O(n)
// S.C=O(1)
