#include "../header.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = nullptr, *n2 = nullptr, *n = head;
        int l = 0;
        while (n != nullptr) {
            ++l;            
            if (l == k) {
                n1 = n;
            }
            n = n->next;
        }
        n = head;
        int t = 0;
        while (n != nullptr) {
            if (t == l - k) {
                n2 = n;
            }
            ++t;            
            n = n->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};