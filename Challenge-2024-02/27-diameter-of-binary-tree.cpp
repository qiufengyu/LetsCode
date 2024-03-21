#include "../header.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* node, int& res) {
        if (node) {
            int l = dfs(node->left, res), r = dfs(node->right, res);
            if (l + r > res) {
                res = l + r;
            }
            return 1 + max(l, r);
        }
        return 0;
    }
};