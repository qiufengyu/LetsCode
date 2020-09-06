#include "../header.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode *temp = getMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

    TreeNode* getMin(TreeNode* root) {
        TreeNode *node = root;
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    int key;
    cin >> key;
    TreeNode *res = Solution().deleteNode(root, key);
    prettyPrintTree(res);
    return 0;
}