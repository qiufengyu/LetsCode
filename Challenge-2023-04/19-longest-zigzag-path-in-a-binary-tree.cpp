#include "../header.h"

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        dfs(root->left, res, 1, true);
        dfs(root->right, res, 1, false);
        return res;
    }

    void dfs(TreeNode* node, int& res, int current, bool left) {
        if (node) {
            res = max(res, current);
            if (left) {
                dfs(node->left, res, 1, true);
                dfs(node->right, res, current + 1, false);
            } else {
                dfs(node->left, res, current + 1, true);
                dfs(node->right, res, 1, false);
            }
        }
    }
};