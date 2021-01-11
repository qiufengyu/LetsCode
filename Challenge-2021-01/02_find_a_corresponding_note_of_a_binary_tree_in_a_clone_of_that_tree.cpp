#include "../header.h"

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *res = nullptr;
        if (original) {
            helper(original, cloned, target, &res);
        }
        return res;
    }

    void helper(TreeNode* n1, TreeNode* n2, const TreeNode* const target, TreeNode** res) {
        if (target == n1) {
            *res = n2;
        } else if (n1 && n2 && !(*res)) {
            helper(n1->left, n2->left, target, res);
            helper(n1->right, n2->right, target, res);
        }
    }
};