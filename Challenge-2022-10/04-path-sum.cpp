#include "../header.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        helper(root, 0, targetSum, res);
        return res;
    }

    void helper(TreeNode* node, int currentSum, int targetSum, bool& res) {
        if (node) {
            currentSum += node->val;
            if (node->left == nullptr && node->right == nullptr) {
                if (currentSum == targetSum) {
                    res = true;
                }
            } else {
                helper(node->left, currentSum, targetSum, res);
                helper(node->right, currentSum, targetSum, res);
            }
        }
    }
};