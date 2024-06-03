#include "../header.h"

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        helper(root, root->left, res);
        helper(root, root->right, res);
        return res;
    }

    void helper(TreeNode* parent, TreeNode* child, int& res) {
        if (child) {
            helper(child, child->left, res);
            helper(child, child->right, res);
            if (child->val != 1) {
                res += abs(child->val - 1);
                parent->val += (child->val - 1);
            }
        }
    }
};