#include "../header.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root) {
            int l = rangeSumBST(root->left, low, high);
            int r = rangeSumBST(root->right, low, high);
            if (root->val >= low && root->val <= high) {
                return root->val + l + r;
            } else {
                return l + r;
            }
        }
        return 0;          
    }
};