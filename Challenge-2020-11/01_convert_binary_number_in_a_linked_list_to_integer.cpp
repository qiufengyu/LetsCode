#include "../header.h"

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode *node = head;
        while (node) {
            res = (res << 1) | node->val;
            node = node->next;
        }
        return res;
    }
};
