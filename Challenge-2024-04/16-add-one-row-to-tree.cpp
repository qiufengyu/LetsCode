#include "../header.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *n = new TreeNode{val, root, nullptr};
            return n;
        }
        if (root) {
            if (depth == 2) {
                root->left = new TreeNode{val, root->left, nullptr};
                root->right = new TreeNode{val, nullptr, root->right};
            } else {                
                addOneRow(root->left, val, depth-1);                
                addOneRow(root->right, val, depth-1);
                
            }
        }        
        return root;
    }
};