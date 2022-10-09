#include "../header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        ListNode *slow = dummy, *fast = dummy;
        dummy->next = head;
        while (n > 0) {
            fast = fast->next; 
            --n;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }        
        slow->next = slow->next->next;        
        return dummy->next;
    }
};