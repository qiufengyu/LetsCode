#include "../header.h"

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = 0, yDepth = 0;
        int xParent = 0, yParent = 0;
        dfs(root, x, y, xDepth, yDepth, 0, xParent, yParent, 0);
        return xDepth == yDepth && xParent != yParent;
    }

    void dfs(TreeNode* node, const int x, const int y, int& xDepth, int& yDepth, int depth, int& xParent, int& yParent, int parent) {
        if (node) {
            if (node->val == x) {
                xDepth = depth;
                xParent = parent;
            } else if (node->val == y) {
                yDepth = depth;
                yParent = parent;
            }
            dfs(node->left, x, y, xDepth, yDepth, depth + 1, xParent, yParent, node->val);
            dfs(node->right, x, y, xDepth, yDepth, depth + 1, xParent, yParent, node->val);
        }
    }
};

int main() {
    string s;
    cin >> s;
    TreeNode *root = stringToTreeNode(s);
    int x, y;
    cin >> x >> y;
    cout << Solution().isCousins(root, x, y) << endl;
    return 0;
}