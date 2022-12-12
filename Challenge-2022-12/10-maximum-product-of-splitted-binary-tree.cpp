#include "../header.h"

class Solution {
public:
    int maxProduct(TreeNode* root) {
        int sum = getSum(root);
        // cout << "total sum = " << sum << endl;
        long maxProduct = 0L;
        dfs(root, sum, maxProduct);
        return (int)(maxProduct % 1000000007);
    }

    int getSum(TreeNode* node) {
        if (node) {
            return node->val + getSum(node->left) + getSum(node->right);
        }
        return 0;
    }

    int dfs(TreeNode* node, int sum, long& maxProduct) {
        if (node) {
            // cout << "current node = " << node->val << endl;
            int l = dfs(node->left, sum, maxProduct);
            int r = dfs(node->right, sum, maxProduct);
            int s = l + r + node->val;
            long p = (long)s * (long)(sum - s);
            if (p > maxProduct) {
                // cout << s << " * " << sum - s << endl;
                maxProduct = p;
            }
            return s;
        }
        return 0L;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    int res = Solution().maxProduct(root);
    cout << res << endl;
    return 0;
}