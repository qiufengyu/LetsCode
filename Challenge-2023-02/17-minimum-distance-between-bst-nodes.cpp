#include "../header.h"

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res = 100001, prev = -1;
        dfs(root, prev, res);
        return res == 100001 ? 0 : res;
    }

    void dfs(TreeNode* node, int& prev, int& res) {
        if (node) {
            dfs(node->left, prev, res);
            int v = node->val;
            if (prev >= 0 && v - prev < res) {
                res = v - prev;
            }
            prev = v;
            dfs(node->right, prev, res);         
        }
    }
};
