#include "../header.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *n1 = head, *n2 = head;
        while (n2 && n2->next) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        return n1;
    }
};