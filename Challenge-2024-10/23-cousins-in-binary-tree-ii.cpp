#include "../header.h"

class Solution {
    void helper(TreeNode* node, vector<long long>& levelSum, int level) {
        if (node) {
            int x = 0;
            if (node->left) {
                x += node->left->val;
            }
            if (node->right) {
                x += node->right->val;
            }
            if (node->left) {
                node->left->val = levelSum[level] - x;
            }
            if (node->right) {
                node->right->val = levelSum[level] - x;
            }
            helper(node->left, levelSum, level + 1);
            helper(node->right, levelSum, level + 1);
        }
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> levelSum;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                long long s = 0LL;
                while (sz) {
                    auto n = q.front();
                    q.pop();
                    s += n->val;
                    if (n->left) {
                        q.push(n->left);
                    }
                    if (n->right) {
                        q.push(n->right);
                    }
                    sz--;
                }
                levelSum.push_back(s);
            }
            root->val = 0;
            helper(root, levelSum, 1);
        }        
        return root;
    }
};