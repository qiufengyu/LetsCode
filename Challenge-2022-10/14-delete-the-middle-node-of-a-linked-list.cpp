#include "../header.h"

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* n1 = dummy, *n2 = dummy;
        while (n2->next && n2->next->next) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        // head can't be nullptr since length >= 1
        n1->next = n1->next->next;
        return dummy->next;
    }
};