#include "../header.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        if (!head) {
          return nullptr;
        }
        ListNode *p = head;
        while (p) {
          ListNode *n = p->next;
          if (n && p->val == p->next->val) {
            while (n && n->val == p->val) {
              n = n->next;
            }
            p = n;
          } else {
            node->next = p;
            p = p->next;
            node = node->next;
          }
        }
        node->next = nullptr;
        return dummy->next;
    }
};

int main() {
  string s;
  cin >> s;
  ListNode *head = stringToListNode(s);
  ListNode *res = Solution().deleteDuplicates(head);
  prettyPrintLinkedList(res);
  return 0;
}