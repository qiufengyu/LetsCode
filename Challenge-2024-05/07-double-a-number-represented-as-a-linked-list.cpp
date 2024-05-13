#include "../header.h"

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *node = reverse(head);
        ListNode *h = node;
        int carry = 0;
        while (node) {
            int val = node->val * 2 + carry;
            carry = val / 10;
            val %= 10;
            node->val = val;
            node = node->next;
        }
        node = reverse(h);
        if (carry) {
            ListNode *h = new ListNode{1, node};
            node = h;
        }
        return node;        
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *current = head, *nxt = nullptr;;
        while (current) {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
};

int main() {
    ListNode *n3 = new ListNode{9, nullptr};
    ListNode *n2 = new ListNode{8, n3};
    ListNode *n1 = new ListNode{1, n2};
    prettyPrintLinkedList(n1);
    n1 = Solution().doubleIt(n1);
    prettyPrintLinkedList(n1);
    return 0;
}