#include "../header.h"

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> v;
        if (root) {
            q.push(root);
            while (!q.empty()) {
                long long s = 0LL;
                int sz = q.size();
                while (sz) {
                    TreeNode* n = q.front();
                    s += n->val;
                    if (n->left) {
                        q.push(n->left);
                    }
                    if (n->right) {
                        q.push(n->right);
                    }
                    q.pop();
                    sz--;
                }
                v.push_back(s);
            }
        }
        sort(v.begin(), v.end());
        if (v.size() >= k) {
            return v[v.size()-k];
        }
        return -1LL;
    }
};