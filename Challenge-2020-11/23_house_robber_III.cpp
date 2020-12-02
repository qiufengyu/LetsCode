#include "../header.h"

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        pair<int, int> current {0, 0};
        current.first = max(left.first, left.second) + max(right.first, right.second);
        current.second = root->val + left.first + right.first;
        return current;
    }
};