#include "../header.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
          if (slow == fast) {
            return true;
          }
          slow = slow->next;
          fast = fast->next->next;
        }
      }
      return false;
    }
};