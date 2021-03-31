#include "../header.h"

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int index = 0;
        helper(root, voyage, index, res);
        if (res.size() > 0 && res[0] == -1) {
          return {-1};
        }
        return res;
    }

    void helper(TreeNode* node, vector<int>& voyage, int& index, vector<int>& res) {
      if (node) {
        if (node->val != voyage[index]) {
          res.clear();
          res.push_back(-1);
          return;
        }
        if (node->left && node->left->val != voyage[index+1]) {
          swap(node->left, node->right);
          res.push_back(node->val);
        }
        ++index;
        helper(node->left, voyage, index, res);
        helper(node->right, voyage, index, res);
      }
    }
};