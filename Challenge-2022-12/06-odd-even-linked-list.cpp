#include "../header.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *h1 = head, *h2 = head->next, *current = h2->next;
        ListNode *head2 = head->next;
        bool flag = true;
        while (current != nullptr) {
            if (flag) {
                h1->next = current;
                h1 = h1->next;
            } else {
                h2->next = current;
                h2 = h2->next;
            }
            flag = !flag;
            current = current->next;
        }
        if (h1) {
            h1->next = head2;
        }
        if (h2) {
            h2->next = nullptr;
        }
        return head;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().oddEvenList(head);
    prettyPrintLinkedList(res);
    return 0;
}