#include "../header.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while (current) {
          if (current->left) {
            TreeNode *p = current->left;
            while (p->right) {
              p = p->right;
            }
            p->right = current->right;
            current->right = current->left;
            current->left = nullptr;
          }
          current = current->right;
        }
    }
};