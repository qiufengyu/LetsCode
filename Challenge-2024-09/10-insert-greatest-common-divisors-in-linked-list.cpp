#include "../header.h"

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *first = head, *second = head->next;
        while (second) {
            int g = gcd(first->val, second->val);
            ListNode *n = new ListNode{g, second};
            first->next = n;
            first = second;
            second = second->next;
        }
        return head;
    }
};