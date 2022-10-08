#include "../header.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            // reverse first half
            ListNode *temp = slow;
            slow = slow->next;
            temp->next = prev;
            prev = temp;
        }
        if (fast != nullptr) {
            slow = slow->next;
        }
        // compare first half (reversed) and second half
        ListNode *n1 = prev, *n2 = slow;
        while (n1 && n2) {
            if (n1->val != n2->val) {
                return false;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        return true;        
    }
};