#include <iostream>
#include "binary_tree.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            vector<int> v;
            int qSize = q.size();
            while(qSize > 0) {
                TreeNode *n = q.front();
                q.pop();
                v.push_back(n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
                qSize--;
            }
            res.push_back(v);
        }
        return res;     
    }
};