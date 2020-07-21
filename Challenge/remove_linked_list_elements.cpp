#include "header.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = head;
        while (newHead != nullptr && newHead->val == val) {
            ListNode *p = newHead;
            newHead = newHead->next;
            delete p;
        }
        if (newHead == nullptr) {
            return newHead;
        }
        ListNode *p = newHead;
        ListNode *c = p->next;
        while (c != nullptr) {
            if (c->val == val) {
                p->next = c->next;
                ListNode *q = c;
                c = c->next;
                delete q;
            } else {
                c = c->next;
                p = p->next;
            }
        }
        return newHead;
    }
};

int main() {
    string s;
    cin >> s;
    int val;
    cin >> val;
    ListNode *head = stringToListNode(s);
    ListNode *r = Solution().removeElements(head, val);
    prettyPrintLinkedList(r);
    return 0;
}