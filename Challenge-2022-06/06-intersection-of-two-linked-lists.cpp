#include "../header.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *na = headA, *nb = headB;
        while (na != nb) {
            na = na->next;
            nb = nb->next;
            if (na == nullptr && nb == nullptr) {
                return nullptr;
            }
            if (na == nullptr) {
                na = headB;
            }
            if (nb == nullptr) {
                nb = headA;
            }
        }
        return na;        
    }
};