#include "../header.h"

/**
 * Also see ../Challenge-2021-06/30_lowest_common_ancestor_of_a_binary_tree.cpp
 * */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        const int mx = max(p->val, q->val), mn = min(p->val, q->val);
        if (root) {
            if (root->val > mx) {
                return lowestCommonAncestor(root->left, p, q);
            } else if (root->val < mn) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                return root;
            }
        }
        return root;
    }
};