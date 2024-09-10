#include "../header.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode *n = head;
        while (n) {
            length++;
            n = n->next;
        }
        int pLength = length / k, pRest = length % k;
        vector<ListNode*> res(k, nullptr);
        n = head;
        int count = 0, groupId = 0;
        while (groupId < k) {
            res[groupId] = n;
            if (groupId < pRest) {                
                for (int i = 0; i < pLength && n != nullptr; i++) {
                    n = n->next;
                }
                ListNode *tmp = n ? n->next : nullptr;
                n->next = nullptr;
                n = tmp;
            } else {
                for (int i = 0; i < pLength - 1 && n != nullptr; i++) {
                    n = n->next;
                }
                ListNode *tmp = n ? n->next : nullptr;
                if (n) {
                    n->next = nullptr;
                }
                n = tmp;
            }
            groupId++;
        }
        return res;
    }
};