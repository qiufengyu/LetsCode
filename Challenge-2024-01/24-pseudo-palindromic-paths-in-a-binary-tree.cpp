#include "../header.h"

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return helper(root, 0);
    }

    int helper(TreeNode* node, int path) {
        if (node) {
            path = path ^ (1 << node->val);
            if (node->left || node->right) {
                return helper(node->left, path) + helper(node->right, path);
            } else {
                if ((path & (path - 1)) == 0) {
                    return 1;
                }
                return 0;
            }            
        }
        return 0;
    }
};