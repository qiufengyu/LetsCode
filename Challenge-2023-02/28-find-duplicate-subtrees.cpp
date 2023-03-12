#include "../header.h"

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> tm;
        helper(root, res, tm);
        return res;
    }

    string helper(TreeNode* node, vector<TreeNode*>& res, unordered_map<string, int>& tm) {
        if (node == nullptr) {
            return "#";
        }
        string left = helper(node->left, res, tm);
        string right = helper(node->right, res, tm);
        int val = node->val;
        string s = "(" + left + ")" + to_string(node->val) + "(" + right + ")";
        if (tm[s] == 1) {
            res.push_back(node);
        }
        ++tm[s];
        return s;
    }
};