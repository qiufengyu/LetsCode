#include "../header.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 1;
        ListNode *prev = list1;
        while (i < a) {
            prev = prev->next;
            i++;
        }
        ListNode *nxt = prev->next;
        prev->next = list2;
        while (i <= b) {
            nxt = nxt->next;
            i++;
        }
        ListNode *h2 = list2;
        while (h2->next) {
            h2 = h2->next;
        }
        h2->next = nxt;
        return list1;
    }
};