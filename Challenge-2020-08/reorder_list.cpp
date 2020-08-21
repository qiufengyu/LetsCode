#include "../header.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);
        ListNode* p = head;
        while (slow != nullptr && slow->next != nullptr) {
            ListNode *temp = p->next;
            ListNode *temp2 = slow;
            slow = slow->next;
            temp2->next = temp;
            p->next = temp2;
            p = temp;
        }
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};