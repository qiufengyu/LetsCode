#include "../header.h"

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        int t = helper(root, res);
        // the root is leaf node
        if (t == 0) {
          return 1 + res;
        }
        return res;
    }

    // 0: not camerad, 1: parent placed a camera, 2: at least one child has a camera
    int helper(TreeNode* node, int& res) {
      if (node == nullptr) {
        return 2;
      }
      int left = helper(node->left, res), right = helper(node->right, res);
      if (left == 0 || right == 0) {
        // should put a camera in current node
        ++res;
        return 1;
      }
      if (left == 1 || right == 1) {
        return 2;
      }
      return 0;
    }
};
