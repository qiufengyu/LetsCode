#include "../header.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *t = head, *l = nullptr, *r = head;
        while (t != nullptr) {
            if (k == 0) {
                r = r->next;
            } else {
                --k;
                l = l == nullptr ? head : l->next;
            }            
            t = t->next;
        }
        swap(l->val, r->val);
        return head;
    }
};

int main() {
    string s;
    cin >> s;
    ListNode *head = stringToListNode(s);
    int k;
    cin >> k;
    ListNode *res = Solution().swapNodes(head, k);
    prettyPrintLinkedList(res);
    return 0;
}