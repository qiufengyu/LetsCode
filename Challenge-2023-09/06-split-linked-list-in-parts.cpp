#include "../header.h"


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int n = 0;
        ListNode *current = head;
        while (current) {
            n++;
            current = current->next;
        }
        int sz = n / k, m = n % k, j = 0;
        current = head;
        ListNode *prev = head;
        for (int i = 0; i < min(k, n); i++) {
            j = (i < m ? -1 : 0);
            prev = current;
            // these groups should have size + 1 elements
            res[i] = current;
            while (j < sz && current) {
                prev = current;
                current = current->next;
                j++;
            }
            prev->next = nullptr;
        }
        return res;
    }
};