#include "../header.h"

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original != nullptr) {
            if (original == target) {
                return cloned;
            
            }
            if (original->left != nullptr) {
                TreeNode* res = getTargetCopy(original->left, cloned->left, target); 
                if (res != nullptr) {
                    return res;
                }
            }
            if (original->right != nullptr) {
                TreeNode* res = getTargetCopy(original->right, cloned->right, target); 
                if (res != nullptr) {
                    return res;
                }
            }
        }        
        return nullptr;
    }
};