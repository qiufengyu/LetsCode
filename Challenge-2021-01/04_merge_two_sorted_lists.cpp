#include "../header.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode(0);
      ListNode* head = dummy;
      while (l1 && l2) {
        if (l1->val <= l2->val) {
          head->next = l1;
          head = head->next;
          l1 = l1->next;
        }
        else {
          head->next = l2;
          head = head->next;
          l2 = l2->next;
        }
      }
      while (l1) {
        head->next = l1;
        head = head->next;
        l1 = l1->next;
      }
      while (l2) {
        head->next = l2;
        head = head->next;
        l2 = l2->next;
      }
      return dummy->next;
    }
};