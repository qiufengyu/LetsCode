#include "../header.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        dfs(root, h);
        return h;
    }

    int dfs(TreeNode* node, int& h) {
        if (node == nullptr) {
            return 0;
        }
        int l = dfs(node->left, h), r = dfs(node->right, h);
        if (l + r > h) {
            h = l + r;
        }
        return 1 + max(l, r);
    }
};