#include "../header.h"

class Solution {
    TreeNode *first, *second, *prev;
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }

    void helper(TreeNode *node) {
        if (node) {
            helper(node->left);
            if (prev && prev->val > node->val) {
                if (first == nullptr) {
                    first = prev;
                }
                second = node;                
            }
            prev = node;
            helper(node->right);
        }
    }
};