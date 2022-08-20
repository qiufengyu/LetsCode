#include "../header.h"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root != nullptr) {
            if (root->val < low) {
                return trimBST(root->right, low, high);
            } else if (root->val > high) {
                return trimBST(root->left, low, high);
            }
            else {
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
                return root;
            }
        }
        return nullptr;
    }
};

int main() {
    string s;
    cin >> s;
    int low, high;
    cin >> low >> high;
    TreeNode *root = stringToTreeNode(s);
    TreeNode *res = Solution().trimBST(root, low, high);
    prettyPrintTree(res);
    return 0;
}