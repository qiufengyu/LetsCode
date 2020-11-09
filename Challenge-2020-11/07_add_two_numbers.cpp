#include "../header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1 || l2) {
            if (l1) {
                s1.push(l1->val);
                l1 = l1->next;
            }
            if (l2) {
                s2.push(l2->val);
                l2 = l2->next;
            }
        }
        ListNode *head = nullptr;
        int t = 0;
        while (!s1.empty() || !s2.empty()) {
            int val;
            if (!s1.empty() && !s2.empty()) {
                val = s1.top() + s2.top() + t;
                s1.pop();
                s2.pop();
            } else if (!s1.empty()) {
                val = s1.top() + t;
                s1.pop();
            } else {
                val = s2.top() + t;
                s2.pop();
            }
            if (val > 9) {
                t = 1;
            } else {
                t = 0;
            }
            val %= 10;
            ListNode *node = new ListNode(val);
            node->next = head;
            head = node;
        }
        if (t > 0) {
            ListNode *node = new ListNode(t);
            node->next = head;
            head = node;
        }
        return head;
    }
};