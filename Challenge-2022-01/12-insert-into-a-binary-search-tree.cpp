#include "../header.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode *p = nullptr, *n = root;
        while (n != nullptr) {
            p = n;
            if (val > n->val) {
                n = n->right;
            } else {
                n = n->left;
            }            
        }
        if (val > p->val) {
            p->right = new TreeNode(val);
        } else {
            p->left = new TreeNode(val);
        }
        return root;
    }
};

int main() {
    string s;
    cin >> s;
    int val;
    cin >> val;
    TreeNode *root = stringToTreeNode(s);
    prettyPrintTree(Solution().insertIntoBST(root, val));
    return 0;
}