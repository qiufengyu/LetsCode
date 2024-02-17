#include "../header.h"


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = 0;
        ListNode *dummy = new ListNode{0, head};
        ListNode *current = dummy, *prev = nullptr, *nxt = nullptr;
        ListNode *start = nullptr, *end = nullptr;
        while (n < left) {
            n++;
            prev = current;
            current = current->next;
        }
        start = current;
        while (n < right) {
            n++;
            current = current->next;
        }
        end = current;
        nxt = current->next;
        // reverse list from start to end
        current = start;
        start = start->next;
        while (current != end) {
            ListNode *tmp = start->next;
            start->next = current;
            current = start;
            start = tmp;
        }
        prev->next->next = start;
        prev->next = current;
        return dummy->next;
    }
};