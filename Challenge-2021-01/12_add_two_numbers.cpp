#include "../header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0);
        ListNode *res = temp;
        int carry = 0;
        while (l1 && l2) {
          int n = l1->val + l2->val + carry;
          temp->next = new ListNode(n % 10);
          carry = n / 10;
          l1 = l1->next;
          l2 = l2->next;
          temp = temp->next;
        }
        while (l1) {
          int n = l1->val + carry;
          temp->next = new ListNode(n % 10);
          carry = n / 10;
          l1 = l1->next;
          temp = temp->next;
        }
        while (l2) {
          int n = l2->val + carry;
          temp->next = new ListNode(n % 10);
          carry = n / 10;
          l2 = l2->next;
          temp = temp->next;
        }
        if (carry) {
          temp->next = new ListNode(1);
        }
        return res->next;
    }
};