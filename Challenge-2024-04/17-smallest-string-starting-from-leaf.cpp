#include "../header.h"

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string res;
        string s;
        helper(root, s, res);
        return res;
    }

    void helper(TreeNode *node, string& s, string& res) {
        if (node) {
            s.push_back('a' + node->val);
            if (node->left || node->right) {
                helper(node->left, s, res);
                helper(node->right, s, res);
            } else {
                string t{s};
                reverse(t.begin(), t.end());
                if (res.size() == 0 || t < res) {
                    res = t;
                }
            }
            s.pop_back();
        }
    }
};