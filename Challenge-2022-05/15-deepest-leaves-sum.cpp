#include "../header.h"

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0, maxDepth = 0;
        if (root != nullptr) {
            traversal(root, res, maxDepth, 0);
        }
        return res;
    }
    
    void traversal(TreeNode* node, int& res, int& maxDepth, int depth) {
        if (maxDepth < depth) {
            maxDepth = depth;
            res = 0;
        }
        if (maxDepth == depth) {
            if (node->left == nullptr && node->right == nullptr) {
                res += node->val;
            }
            if (node->left != nullptr) {
                traversal(node->left, res, maxDepth, depth + 1);
            }
            if (node->right != nullptr) {
                traversal(node->right, res, maxDepth, depth + 1);
            }
        } else {
            if (node->left != nullptr) {
                traversal(node->left, res, maxDepth, depth + 1);
            }
            if (node->right != nullptr) {
                traversal(node->right, res, maxDepth, depth + 1);
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode* root = stringToTreeNode(s);
    cout << Solution().deepestLeavesSum(root) << endl;
    return 0;
}