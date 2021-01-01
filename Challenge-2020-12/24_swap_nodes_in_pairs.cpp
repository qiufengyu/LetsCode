#include "../header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head;
        if (res == nullptr || res->next == nullptr) {
          return res;
        }
        // head has at least 2 nodes
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *current = dummy->next;
        while(current && current->next) {
          ListNode* temp = current->next->next;
          prev->next = current->next;
          current->next->next = current;
          prev = current;
          current->next = temp;          
          current = temp;          
        }
        return dummy->next;
    }
};

int main() {
  string s;
  cin >> s;
  ListNode* root = stringToListNode(s);
  ListNode* res = Solution().swapPairs(root);
  prettyPrintLinkedList(res);
  return 0;
}