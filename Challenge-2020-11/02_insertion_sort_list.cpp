#include "../header.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *current = head;
        ListNode *start = dummy;
        while (current != nullptr) {
            start = dummy;
            while (start->next && start->next->val <= current->val) {
                start = start->next;
            }
            ListNode *tmp = current->next;
            current->next = start->next;
            start->next = current;
            current = tmp;
        }
        return dummy->next;
    }
};