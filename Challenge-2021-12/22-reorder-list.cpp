#include "../header.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        // find mid
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse second half part
        fast = reverse(slow->next);
        // weave the new list
        slow->next = nullptr;
        slow = head;
        while (slow != nullptr && fast != nullptr) {
            ListNode *sn = slow->next;
            ListNode *fn = fast->next;
            slow->next = fast;
            fast->next = sn;
            slow = sn;
            fast = fn;
        }
    }

    ListNode *reverse(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *prev = head, *current = head->next;
        head->next = nullptr;
        while (current != nullptr) {
            ListNode* nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    Solution().reorderList(head);
    prettyPrintLinkedList(head);
    return 0;
}