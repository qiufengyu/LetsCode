#include "../header.h"

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root) {
            helper(root, root->left, target, true);
            helper(root, root->right, target, false);
            if (root->left == nullptr && root->right == nullptr && root->val == target) {
                root = nullptr;
            }
        }
        return root;        
    }

    void helper(TreeNode* parent, TreeNode* child, int target, bool b) {
        if (child) {
            helper(child, child->left, target, true);
            helper(child, child->right, target, false);
            if (child->left == nullptr && child->right == nullptr && child->val == target) {
                if (b) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
                delete child;
            }
        }
    }
};