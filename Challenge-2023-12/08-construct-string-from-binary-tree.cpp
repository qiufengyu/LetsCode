#include "../header.h"

class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root) {
            if (root->left && root->right) {
                return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
            } else if (root->left) {
                return to_string(root->val) + "(" + tree2str(root->left) + ")";
            } else if (root->right) {
                return to_string(root->val) + "()(" + tree2str(root->right) + ")";
            } else {
                return to_string(root->val);
            }
        }
        return "";
    }    
};