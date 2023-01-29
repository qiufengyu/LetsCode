#include "../header.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode* node, vector<int>& res) {
        if (node) {
            res.push_back(node->val);
            dfs(node->left, res);
            dfs(node->right, res);
        }
    }
};
