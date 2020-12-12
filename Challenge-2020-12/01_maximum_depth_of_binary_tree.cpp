#include "../header.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (root) {
            maxDepth(root, 1, res);
        }
        return res;
    }

    void maxDepth(TreeNode* root, int level, int& res) {
        if (level > res) {
            res = level;
        }
        if (root->left) {
            maxDepth(root->left, level+1, res);
        }
        if (root->right) {
            maxDepth(root->right, level+1, res);
        }
    }
};