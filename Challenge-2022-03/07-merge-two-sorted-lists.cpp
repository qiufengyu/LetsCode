#include "../header.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                res->next = list1;
                list1 = list1->next;
            } else {
                res->next = list2;
                list2 = list2->next;
            }
            res = res->next;
        }
        if (list1 != nullptr) {
            res->next = list1;
        } else {
            res->next = list2;
        }
        return dummy->next;
    }
};