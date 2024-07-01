#include "../header.h"

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }

    int helper(TreeNode* node, int& sum) {
        if (node) {
            int r = helper(node->right, sum);
            node->val = node->val + max(r, sum);
            sum = max(sum, node->val);
            helper(node->left, sum);
            return node->val;            
        }
        return 0;
    }
};