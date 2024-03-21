#include "../header.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> mp;
        int preSum = 0;
        ListNode *current = head;
        mp[0] = dummy;
        while (current) {
            preSum += current->val;
            mp[preSum] = current;
            current = current->next;
        }
        preSum = 0;
        // edge case for [1, -1]
        current = dummy;
        while (current) {
            preSum += current->val;
            current->next = mp[preSum]->next;
            current = current->next;
        }
        return dummy->next;
    }
};