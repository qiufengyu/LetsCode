#include "../header.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }

    int dfs(TreeNode* node, int& maxPath) {
        if (node) {
            int l = max(0, dfs(node->left, maxPath));
            int r = max(0, dfs(node->right, maxPath));
            int p = l + r + node->val;
            if (p > maxPath) {
                maxPath = p;
            }
            return max(l + node->val, r + node->val);
        }
        return 0;
    }
};