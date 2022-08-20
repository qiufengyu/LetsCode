#include "../header.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        f(root);
    }

    TreeNode *f(TreeNode* node) {
        if (node) {
            TreeNode *t = node->right;
            node->right = f(node->left);
            node->left = nullptr;
            TreeNode *r = node->right;
            if (r) {
                while (r->right) {
                    r = r->right;
                }
                r->right = f(t);
            } else {
                node->right = f(t);
            }         
            return node;
        }
        return nullptr;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    Solution().flatten(root);
    prettyPrintTree(root);
    return 0;
}