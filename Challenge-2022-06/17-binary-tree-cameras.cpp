#include "../header.h"

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        return dfs(root, res) == 0 ? 1 + res : res;
    }

    // return 0: leaf node
    // return 1: parent node of leaf node, current node needs camera
    // return 2: others, child node is comeraed, no need to place
    int dfs(TreeNode *node, int& res) {
        if (node == nullptr) {
            return 2;
        }
        int left = dfs(node->left, res), right = dfs(node->right, res);
        if (left == 0 || right == 0) {
            ++res;
            return 1;
        }
        // if left == 2, right == 2, then current node is a leaf
        return left == 1 || right == 1 ? 2 : 0;
    }
};