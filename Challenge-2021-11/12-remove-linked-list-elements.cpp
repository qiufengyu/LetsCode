#include "../header.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *current = head, *prev = dummy;
        while (current != nullptr) {
            while (current != nullptr && current->val == val) {
                current = current->next;
            }
            prev->next = current;
            prev = prev->next;
            if (current != nullptr) {
                current = current->next;
            }
        }
        return dummy->next;         
    }
};

int main() {
    string s;
    cin >> s;
    int val = 0;
    cin >> val;
    ListNode *head = stringToListNode(s);
    prettyPrintLinkedList(Solution().removeElements(head, val));
    return 0;
}