#include "../header.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int mx = root->val, mn = root->val;
        return max(dfs(root->left, mx, mn), dfs(root->right, mx, mn));
    }

    int dfs(TreeNode* node, int mx, int mn) {
        if (node == nullptr) {
            return mx - mn;
        }
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        return max(dfs(node->left, mx, mn), dfs(node->right, mx, mn));
    }
};