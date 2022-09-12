#include "../header.h"

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root) {
            if (root->left) {
                root->left = pruneTree(root->left);
            }
            if (root->right) {
                root->right = pruneTree(root->right);
            }
            if (root->left == nullptr && root->right == nullptr && root->val == 0) {
                return nullptr;
            }
        }
        return root;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    TreeNode *res = Solution().pruneTree(root);
    prettyPrintTree(res);
    return 0;
}