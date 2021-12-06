#include "../header.h"

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }

    pair<int, int> helper(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        pair<int, int> l = helper(node->left);
        pair<int, int> r = helper(node->right);
        pair<int, int> res {0, 0};
        res.first = max(l.first, l.second) + max(r.first, r.second); // not rob here
        res.second = node->val + l.first + r.first; // rob here
        return res;
    }
};