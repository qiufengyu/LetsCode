#include "../header.h"

class Solution {
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left || root->right) {
      return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    return 1;
  }

  void sumHelper(TreeNode* root, int& res, int depth, const int md) {
    if (root == nullptr) {
      return;
    }
    if (md == depth) {
      res += root->val;
    } else {
      sumHelper(root->left, res, depth+1, md);
      sumHelper(root->right, res, depth+1, md);
    }
  }
public:
  int deepestLeavesSum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int md = maxDepth(root);
    int res = 0;
    sumHelper(root, res, 1, md);
    return res;
  }
};