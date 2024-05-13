#include "../header.h"

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> v;
        ListNode *node = head;
        while (node) {
            while (v.size() > 0 && v.back()->val < node->val) {
                v.pop_back();
            }
            v.push_back(node);
            node = node->next;
        }
        ListNode *res;
        if (v.size() > 0) {
            res = v[0];
        }
        ListNode *n = res;
        for (int i = 1; i < v.size(); i++) {
            n->next = v[i];
            n = n->next;
        }
        if (n) {
            n->next = nullptr;
        }
        return res;
    }
};