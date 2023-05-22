#include "../header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next) {
            ListNode *nxt = head->next;
            ListNode *nnxt = head->next->next;
            nxt->next = head;
            head->next = swapPairs(nnxt);
            return nxt;
        }
        return head;        
    }
};