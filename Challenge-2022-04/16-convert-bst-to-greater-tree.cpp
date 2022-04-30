#include "../header.h"

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }

    void helper(TreeNode* node, int& sum) {
        if (node != nullptr) {
            helper(node->right, sum);
            sum += node->val;
            node->val = sum;
            helper(node->left, sum);
        }
    }
};