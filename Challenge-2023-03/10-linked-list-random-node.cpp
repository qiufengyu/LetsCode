#include "../header.h"
#include <random>

class Solution {
    ListNode *head;
public:
    Solution(ListNode* head): head{head} {
    }
    
    int getRandom() {
        ListNode *n = head;
        int count = 0, res = 0;
        while (n != nullptr) {
            ++count;
            if ((rand() % count) == 0) {
                res = n->val;
            }
            n = n->next;
        }
        return res;    
    }
};