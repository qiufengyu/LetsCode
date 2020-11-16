#include "../header.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        help(root, low, high, sum);
        return sum;
    }

    void help(TreeNode *root, int low, int high, int &sum) {
        if (root) {
            if (root->val >= low && root->val <= high) {
                sum += root->val;
            }
            help(root->left, low, high, sum);
            help(root->right, low, high, sum);
        }
    }
};