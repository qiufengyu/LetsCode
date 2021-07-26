#include "../header.h"

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *dummy = new TreeNode(-1);
        dummy->left = root;
        helper(root, dummy, true);
        return dummy->left;
    }

    void helper(TreeNode *node, TreeNode* parent, bool leftOrRight) {
        if (node->left) {
            helper(node->left, node, true);
        }
        if (node->right) {
            helper(node->right, node, false);
        }
        if (node->left == nullptr && node->right == nullptr && node->val == 0) {
            if (leftOrRight) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    prettyPrintTree(Solution().pruneTree(root));
    return 0;
}