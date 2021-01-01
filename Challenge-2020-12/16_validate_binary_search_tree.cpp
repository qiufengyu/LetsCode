#include "../header.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        helper(root, nodes);
        print_vector<int>(nodes);
        for (int i = 1; i < nodes.size(); i++) {
          if (nodes[i-1] >= nodes[i]) {
            return false;
          }
        }
        return true;
    }
    void helper(TreeNode* root, vector<int>& nodes) {
      if (root) {
        helper(root->left, nodes);
        nodes.push_back(root->val);
        helper(root->right, nodes);
      }
    }
};

int main() {
  string s;
  cin >> s;
  TreeNode* root = stringToTreeNode(s);
  cout << Solution().isValidBST(root) << endl;
  return 0;
}