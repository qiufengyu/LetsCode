#include "../header.h"

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode = new TreeNode(val);
        if (root == nullptr) {
            root = newNode;
        } else {
            TreeNode* parent = helper(root, val);
            if (val < parent->val) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
        return root;
    }

    TreeNode *helper(TreeNode *root, int val) {
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        if (root->val < val) {
            if (root->right) {
                return helper(root->right, val);
            } else {
                return root;
            }
        }
        else {
            if (root->left) {
                return helper(root->left, val);
            } else {
                return root;
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    int val;
    cin >> val;
    TreeNode* res = Solution().insertIntoBST(root, val);
    prettyPrintTree(res);
    return 0;
}
