#include "../header.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0);
        ListNode *n1 = h1, *n2 = h2;
        while (head != nullptr) {
            if (head->val < x) {
                n1->next = head;
                n1 = n1->next;
            } else {
                n2->next = head;
                n2 = n2->next;
            }
            head = head->next;
        }
        n1->next = h2->next;
        n2->next = nullptr;
        ListNode *res = h1->next;
        delete h1, h2;
        return res;
    }
};

int main() {
    string s;
    int x;
    cin >> s;
    cin >> x;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().partition(head, x);
    prettyPrintLinkedList(res);
    return 0;
}