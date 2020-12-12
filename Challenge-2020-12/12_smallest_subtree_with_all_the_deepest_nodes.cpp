#include "../header.h"

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto res = depth(root);
        return res.second;
    }

    pair<int, TreeNode*> depth(TreeNode* root) {
      if (root == nullptr) {
        return {-1, nullptr};
      }
      auto l = depth(root->left);
      auto r = depth(root->right);
      int dl = l.first;
      int dr = r.first;
      TreeNode *node = dl == dr ? root : (dl >  dr? l.second : r.second);
      return { max(dl, dr) + 1, node };
    }
};