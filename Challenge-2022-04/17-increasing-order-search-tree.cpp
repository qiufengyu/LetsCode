#include "../header.h"

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *node = new TreeNode(-1);
        TreeNode *res = node;
        helper(node, root);
        return res->right;
    }

    void helper(TreeNode *node, TreeNode* current) {
        if (current->left) {
            helper(node, current->left);
        }
        while (node->right) {
            node = node->right;
        }
        node->right = new TreeNode(current->val);        
        if (current->right) {
            helper(node, current->right);
        }        
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    TreeNode *res = Solution().increasingBST(root);
    prettyPrintTree(res);
    return 0;
}