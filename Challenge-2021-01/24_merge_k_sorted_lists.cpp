#include "../header.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }
        if (k == 1) {
            return lists[0];
        }
        int i = 1;
        dummy->next = lists[0];
        while (i < k) {
            // merge two list at one time
            ListNode* l1 = dummy->next;
            ListNode* l2 = lists[i];
            ListNode* head = dummy;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    head->next = l1;
                    l1 = l1->next;
                } else {
                    head->next = l2;
                    l2 = l2->next;
                }
                head = head->next;
            }
            if (l1) {
                head->next = l1;
            }
            if (l2) {
                head->next = l2;
            }
            i++;
        }
        return dummy->next;
    }
};
