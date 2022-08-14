#include "../header.h"

class Solution {
    bool firstFlag = true;
    int prev = 0;
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }         
        if (!isValidBST(root->left)) {
            return false;
        }        
        if (prev >= root->val) {
            if (firstFlag) {
                firstFlag = false;
            } else {
                return false;
            }
        }
        if (firstFlag) {
            firstFlag = false;
        }
        prev = root->val;
        if (!isValidBST(root->right)) {
            return false;
        }
        return true;
    }
};