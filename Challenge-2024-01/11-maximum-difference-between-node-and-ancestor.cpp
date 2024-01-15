#include "../header.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = -1;
        helper(root, res, root->val, root->val);
        return res;
    }

    void helper(TreeNode* node, int& res, int mx, int mn) {
        if (node) {
            res = max(res, max(abs(mx - node->val), abs(mn - node->val)));
            mn = min(mn, node->val);
            mx = max(mx, node->val);
            helper(node->left, res, mx, mn);
            helper(node->right, res, mx, mn);
        }
    }
};