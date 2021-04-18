#include "../header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (i < n) {
          fast = fast->next;
          i++;
        }
        while (fast) {
          fast = fast->next;
          prev = slow;
          slow = slow->next;
        }
        if (prev) {
          prev->next = slow->next;
        }
        else {
          return head->next; // remove first node
        }
        return head;
    }
};