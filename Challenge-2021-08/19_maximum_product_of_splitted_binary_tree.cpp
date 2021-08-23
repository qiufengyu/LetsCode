#include "../header.h"

class Solution {
public:
    int maxProduct(TreeNode* root) {
        long total = 0L;
        totalSum(root, total);
        long res = 0L;
        postTravesal(root, total, res);
        return (int)(res % 1000000007);
    }

    void totalSum(TreeNode *node, long& sum) {
        if (node != nullptr) {
            sum += node->val;
            totalSum(node->left, sum);
            totalSum(node->right, sum);
        }
    }

    long postTravesal(TreeNode *node, const long totalSum, long& res) {
        if (node != nullptr) {
            long l = postTravesal(node->left, totalSum, res);
            long r = postTravesal(node->right, totalSum, res);
            res = max(res, l * (totalSum - l));
            res = max(res, r * (totalSum - r));
            return l + r + node->val;
        }
        return 0;
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    cout << Solution().maxProduct(root) << endl;
    return 0;
}