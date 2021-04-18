#include "../header.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* one = new ListNode(0);
        ListNode* two = new ListNode(0);
        ListNode* o = one, *t = two;
        while(head != nullptr) {
          if (head->val < x) {
            o->next = head;
            o = o->next;
          } else {
            t->next = head;
            t = t->next;
          }
          head = head->next;
        }
        t->next = nullptr;
        o->next = two->next;
        return one->next;
    }
};