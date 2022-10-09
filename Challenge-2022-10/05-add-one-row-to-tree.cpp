#include "../header.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *n = new TreeNode(val, root, nullptr);
            return n;
        }
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        while (currentDepth < depth - 1) {
            int sz = q.size();
            while (sz > 0) {
                TreeNode *n = q.front();
                q.pop();
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
                --sz;
            }
            ++currentDepth;
        }
        int sz = q.size();
        while (sz > 0) {
            TreeNode *n = q.front();
            q.pop();
            TreeNode *t = new TreeNode(val, n->left, nullptr);
            n->left = t;
            TreeNode *tt = new TreeNode(val, nullptr, n->right);
            n->right = tt;
            --sz;
        }
        return root;
    }
};