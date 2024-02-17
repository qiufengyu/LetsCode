#include "../header.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root != nullptr) {
            return helper(root->left, root->right);
        }
        return true;
    }
    
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            if (left->val == right->val) {
                return helper(left->left, right->right) && helper(left->right, right->left);
            }
        }
        return false;
    }
};

