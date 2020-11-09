#include "../header.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        ancestorMaxMin(root, res, root->val, root->val);
        return res;
    }

    void ancestorMaxMin(TreeNode* root, int& res, int maxAncestor, int minAncestor) {
        if (root != nullptr) {
            int d1 = abs(root->val - minAncestor);
            int d2 = abs(root->val - maxAncestor);
            res = max(max(res, d1), d2);
            ancestorMaxMin(root->left, res, max(maxAncestor, root->val), min(minAncestor, root->val));
            ancestorMaxMin(root->right, res, max(maxAncestor, root->val), min(minAncestor, root->val));
        }
    }
};