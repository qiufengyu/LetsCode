#include "../header.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;        
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            bool flag = false;
            while (!q.empty()) {
                int sz = q.size();
                vector<int> v;
                while (sz > 0) {
                    TreeNode* n = q.front();
                    q.pop();
                    v.push_back(n->val);
                    if (n->left) {
                        q.push(n->left);
                    }
                    if (n->right) {
                        q.push(n->right);
                    }
                    --sz;
                }
                if (flag) {
                    reverse(v.begin(), v.end())        ;
                }
                flag = (!flag);
                res.push_back(v);                
            }
        }
        return res;
    }
};