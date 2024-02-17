#include "../header.h"

class Solution {
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if (l1) {
            node->next = l1;
        }
        if (l2) {
            node->next = l2;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        }
        if (n == 1) {
            return lists[0];
        }
        ListNode *start = lists[0];
        for (int i = 1; i < n; ++i) {
            start = merge(start, lists[i]);
        }
        return start;
    }
};