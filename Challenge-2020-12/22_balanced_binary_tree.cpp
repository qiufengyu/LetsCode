#include "../header.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        getHeight(root, res);
        return res;
    }

    int getHeight(TreeNode* node, bool& res) {
      if (node != nullptr) {
        int l = getHeight(node->left, res);
        int r = getHeight(node->right, res);
        if (abs(l - r) > 1) {
          res = false;
        }
        return 1 + max(l, r);
      } else {
        return 0;
      }   
    }
};

int main() {
  string s;
  cin >> s;
  TreeNode *root = stringToTreeNode(s);
  cout << Solution().isBalanced(root) << endl;
  return 0;
}