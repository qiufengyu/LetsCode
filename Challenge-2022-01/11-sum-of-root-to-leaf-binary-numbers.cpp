#include "../header.h"

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, current = 0;
        helper(root, sum, current);
        return sum;
    }

    void helper(TreeNode *node, int& sum, int current) {
        if (node) {
            current = current * 2 + node->val;
            if (node->left || node->right) {
                helper(node->left, sum, current);
                helper(node->right, sum, current);
            } else {
                // cout << current << endl;
                sum += current;
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().sumRootToLeaf(root) << endl;
    return 0;
}