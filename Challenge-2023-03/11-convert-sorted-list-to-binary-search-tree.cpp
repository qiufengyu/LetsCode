#include "../header.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        return helper(head, tail);
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if (end == nullptr) {
            return nullptr;
        }
        cout << start->val << " to " << end->val << endl;
        if (start == end) {
            return new TreeNode(start->val);
        }
        ListNode* s = start, *f = start, *prev = nullptr;
        while (f && f->next && f != end && f->next != end) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        TreeNode* n = new TreeNode(s->val);
        n->left = helper(start, prev);
        n->right = helper(s->next, end);
        return n;
    }
};

int main() {
    string s = "[-10,-3,0,5,9]";
    ListNode *head = stringToListNode(s);
    TreeNode *root = Solution().sortedListToBST(head);
    prettyPrintTree(root);
    return 0;
}