#include "../header.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if (root) {
            helper(root->left, true, res);
            helper(root->right, false, res);
        }
        return res;        
    }

    void helper(TreeNode* node, bool fromLeft, int& res) {
        if (node) {
            if (node->left || node->right) {
                helper(node->left, true, res);
                helper(node->right, false, res);
            } else if (fromLeft) {
                res += node->val;
            }
        }
    }
};