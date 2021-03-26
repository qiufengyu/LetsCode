#include "../header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* h = head;
        vector<ListNode*> l;
        while (h) {
            l.push_back(h);
            h = h->next;
        }
        int sz = l.size();
        int temp = l[sz - k]->val;
        l[sz - k]->val = l[k-1]->val;
        l[k-1]->val = temp;
        return head;
    }
};
