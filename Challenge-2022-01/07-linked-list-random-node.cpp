#include "../header.h"

class Solution {
    int count;
    ListNode *node;
public:
    Solution(ListNode* head): count {0}, node {head} {
        
    }
    
    int getRandom() {
        int res = node->val;
        ListNode *temp = node->next;
        count = 1;
        while (temp) {
            ++count;
            int j = rand() % count;
            if (j == 0) {
                res = temp->val;
            }
            temp = temp->next;
        }
        return res;
    }
};
