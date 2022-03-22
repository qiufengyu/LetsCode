#include "../header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *res = new ListNode(0), *head = res;
        int sum = 0, flag = 0;
        while (l1 != nullptr || l2 != nullptr) {
            sum = ((l1 != nullptr) ? l1->val : 0 ) + ((l2 != nullptr) ? l2->val : 0) + flag;
            flag = sum / 10;
            res->next = new ListNode(sum % 10);
            res = res->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (flag != 0) {
            res->next = new ListNode(flag);
        }
        return head->next;
    }
};