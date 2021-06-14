#include "../header.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pIndex = 0, is = 0, ie = inorder.size();
        TreeNode* root = helper(preorder, inorder, pIndex, is, ie);
        return root;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pIndex, int is, int ie) {
      if (is >= ie) {
        return nullptr;
      }
      TreeNode *current = new TreeNode(preorder[pIndex]);
      int p = preorder[pIndex];
      int it = find(inorder.begin() + is, inorder.begin() + ie, p) - inorder.begin();
      current->left = helper(preorder, inorder, pIndex + 1, is, it);
      int leftLength = it - is;
      current->right = helper(preorder, inorder, pIndex + 1 + leftLength, it + 1, ie);
      return current;
    }
};

int main() {
  vector<int> preorder {3,9,20,15,7}, inorder {9,3,15,20,7};
  TreeNode *root = Solution().buildTree(preorder, inorder);
  prettyPrintTree(root);
  return 0;
}