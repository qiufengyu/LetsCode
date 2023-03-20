#include "../header.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0, current = 0;
        helper(root, res, current);
        return res;
    }

    void helper(TreeNode* node, int& res, int current) {
        if (node) {
            current = current * 10 + node->val;
            if (node->left == nullptr && node->right == nullptr) {
                res += current;
            } else {
                helper(node->left, res, current);
                helper(node->right, res, current);
            }            
            current /= 10;
        }        
    }
};