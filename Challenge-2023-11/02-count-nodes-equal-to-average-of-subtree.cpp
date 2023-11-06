#include "../header.h"

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        postOrder(root, res);
        return res;
    }

    pair<int, int> postOrder(TreeNode* node, int& res) {
        if (node) {
            auto l = postOrder(node->left, res);
            auto r = postOrder(node->right, res);
            int s = l.first + r.first + node->val;
            int c = l.second + r.second + 1;
            if (s / c == node->val) {
                ++res;
            }
            return {s, c};
        }
        return {0, 0};
    }
};