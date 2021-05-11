#include "../header.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if (head == nullptr) {
        return nullptr;
      }
      TreeNode *res = helper(head, nullptr);
      return res;
    }

    TreeNode* helper(ListNode* head, ListNode* tail) {
      if (head == tail) {
        return nullptr;
      }
      ListNode* slow = head, *fast = head;
      while (fast != tail && fast ->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
      }
      TreeNode *parent = new TreeNode(slow->val);
      parent->left = helper(head, slow);
      parent->right = helper(slow->next, tail);
      return parent;     
    }
};