#include "../header.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *current = dummy;
        ListNode *prev = head, *nxt = head->next;
        while (prev != nullptr) {
            nxt = prev->next;
            if (nxt != nullptr && prev->val == nxt->val) {
                while (nxt != nullptr && prev->val == nxt->val) {
                    nxt = nxt->next;
                }
                prev = nxt;
            } else {
                current->next = prev;
                prev = prev->next;
                current = current->next;
            }            
        }
        current->next = nullptr;
        return dummy->next;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    ListNode *res = Solution().deleteDuplicates(head);
    prettyPrintLinkedList(res);
    return 0;
}