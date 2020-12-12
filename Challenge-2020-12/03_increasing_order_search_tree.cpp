#include "../header.h"

class Solution {
private:
  TreeNode* prev;
  void inorder(TreeNode* current) {
    if (current == nullptr) {
      return;
    }
    inorder(current->left);
    prev->right = current;
    prev = current;
    prev->left = nullptr;
    inorder(current->right);
  }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode{0};
        prev = dummy;
        inorder(root);
        return dummy->right;
    }
};