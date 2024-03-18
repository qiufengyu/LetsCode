#include "../header.h"


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head) {
            ListNode *ln = head;        
            int count = 1;
            while (ln->next) {
                count++;
                ln = ln->next;
            }
            int rest = count - n;
            ListNode *prev = nullptr;
            ln = head;
            while (rest > 0) {
                prev = ln;
                ln = ln->next;
                rest--;
            }
            if (prev) {
                prev->next = ln->next;
                delete ln;
            } else {
                prev = head;
                head = head->next;
                delete prev;
            }
        }
        return head;
    }
};