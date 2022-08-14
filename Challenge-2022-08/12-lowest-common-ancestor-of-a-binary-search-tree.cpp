#include "../header.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        int val = root->val, pval = p->val, qval = q->val;
        if (pval < val && qval < val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (pval > val && qval > val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;        
    }
};