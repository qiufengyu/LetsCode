#include "../header.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int current = 0;
        if (root == nullptr) {
            return 0;
        }
        helper(root, current, res);
        return res;
    }

    void helper(TreeNode* root, int current, int& res) {
        if (root->left == nullptr && root->right == nullptr) {
            res += (current * 10 + root->val);
        } else {
            if (root->left) {
                helper(root->left, current * 10 + root->val, res);
            }
            if (root->right) {
                helper(root->right, current * 10 + root->val, res);
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().sumNumbers(root) << endl;
    return 0;
}