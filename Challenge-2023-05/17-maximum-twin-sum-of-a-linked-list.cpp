#include "../header.h"

class Solution {
public:
    int pairSum(ListNode* head) {
        int res = INT_MIN;
        stack<int> st;
        // head is not null ensured by the problem description
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow: the start of the second half
        while (slow && (!st.empty())) {
            res = max(res, slow->val + st.top());
            st.pop();
            slow = slow->next;
        }
        return res;
    }
};