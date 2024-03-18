#include "../header.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head) {
            ListNode *n1 = head, *n2 = head->next;
            while (n1 && n2 && n2->next) {
                if (n1 == n2) {
                    return true;
                }
                n1 = n1->next;
                n2 = n2->next->next;
            }
        }
        return false;
    }
};