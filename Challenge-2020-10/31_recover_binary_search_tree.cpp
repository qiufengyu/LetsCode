#include "../header.h"

class Solution {
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        if (prev && prev->val > node->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = node;
        }
        prev = node;
        inorder(node->right);
    }
};

