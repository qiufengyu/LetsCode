#include "../header.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        traversal(root, low, high, res);
        return res;
    }

    void traversal(TreeNode* node, int low, int high, int& res) {
        if (node) {
            traversal(node->left, low, high, res);
            traversal(node->right, low, high, res);
            if (low <= node->val && high >= node->val) {
                res += node->val;
            }
        }
    }
};