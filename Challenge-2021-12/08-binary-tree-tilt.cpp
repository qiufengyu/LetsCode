#include "../header.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode *node, int& ans) {
        if (node != nullptr) {
            int l = helper(node->left, ans);
            int r = helper(node->right, ans);
            int res = node->val + l + r;
            ans += abs(l - r);
            return res;
        }
        return 0;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    cout << Solution().findTilt(root) << endl;
    return 0;
}