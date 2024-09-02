#include "../header.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* node, vector<int>& res) {
        if (node) {
            helper(node->left, res);
            helper(node->right, res);
            res.push_back(node->val);
        }
    }
};