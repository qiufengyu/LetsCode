#include "header.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                invertTree(root->left);
            }
            if (root->right != nullptr) {
                invertTree(root->right);
            }
            TreeNode *t = root->right;
            root->right = root->left;
            root->left = t;
        }
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode{4};
    TreeNode *l1_1 = new TreeNode{2};
    TreeNode *l1_2 = new TreeNode{7};
    root->left = l1_1;
    root->right = l1_2;
    TreeNode *l2_1 = new TreeNode{1};
    TreeNode *l2_2 = new TreeNode{3};
    TreeNode *l2_3 = new TreeNode{6};
    TreeNode *l2_4 = new TreeNode{9};
    l1_1->left = l2_1;
    l1_1->right = l2_2;
    l1_2->left = l2_3;
    l1_2->right = l2_4;
    TreeNode *res = Solution().invertTree(root);
    prettyPrintTree(res);
    return 0;
}