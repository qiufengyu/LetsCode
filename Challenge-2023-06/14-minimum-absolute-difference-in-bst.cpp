#include "../header.h"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, prev = -100001;
        dfs(root, res, prev);
        return res;        
    }

    void dfs(TreeNode* root, int& res, int& prev) {
        if (root->left) {
            dfs(root->left, res, prev);
        }
        res = min(res, abs(root->val - prev));
        prev = root->val;
        if (root->right) {
            dfs(root->right, res, prev);
        }
    }
};