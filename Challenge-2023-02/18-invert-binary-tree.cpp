#include "../header.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode* l = invertTree(root->left);
            TreeNode* r = invertTree(root->right);
            root->left = r;
            root->right = l;
        }
        return root;
    }
};
