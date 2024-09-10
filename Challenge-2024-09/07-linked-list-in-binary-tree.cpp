#include "../header.h"

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        } if (root == nullptr) {
            return false;
        } else if (check(head, root)) {
            return true;
        } 
        return isSubPath(head, root->left) || isSubPath(head, root->right);        
    }

    bool check(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr || root->val != head->val) {
            return false;
        }
        return check(head->next, root->left) || check(head->next, root->right);
    }
};