#include "../header.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if (head == nullptr || head->next == nullptr) {
        return true;
      }
      ListNode *slow = head, *fast = head;
      while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode *prev = slow->next;
      ListNode *mid = prev->next;
      // list length = 2
      if (mid == nullptr) {
        return prev->val == head->val;
      }
      ListNode *temp = mid->next;
      prev->next = nullptr;
      while (mid) {
        temp = mid->next;
        mid->next = prev;
        prev = mid;
        mid = temp; 
      }
      ListNode *h = head;
      while (prev) {
        if (prev->val != h->val) {
          return false;
        }
        prev = prev->next;
        h = h->next;
      }
      return true;
    }
};