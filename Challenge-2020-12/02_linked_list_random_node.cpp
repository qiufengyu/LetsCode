#include "../header.h"

class Solution {
private:
  int length;
  ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        length = 0;
        ListNode *current = head;
        while (current) {
          length += 1;
          current = current->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int t = rand() % length;
        ListNode* current = head;
        while (t) {
          current = current->next;
          t--;
        }
        return current->val;
    }
};
