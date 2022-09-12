#include "../header.h"

struct NodeLevel {
    TreeNode *node;
    int row;
    int col;
    NodeLevel(TreeNode *_n, int _r, int _c): node {_n}, row {_r}, col {_c} {}
};

typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<NodeLevel*> q;
        map<int, vector<PII>> m;
        vector<vector<int>> res;
        if (root) {
            q.push(new NodeLevel(root, 0, 0));
            while (!q.empty()) {
                int sz = q.size();
                while (sz > 0) {
                    NodeLevel *nl = q.front();
                    q.pop();
                    TreeNode *n = nl->node;
                    int r = nl->row, c = nl->col;                    
                    m[c].push_back({r, n->val});
                    if (n->left) {
                        q.push(new NodeLevel(n->left, r+1, c-1));
                    }
                    if (n->right) {
                        q.push(new NodeLevel(n->right, r+1, c+1));
                    }
                    --sz;
                }
            }
        }
        // construct res from m
        for (auto e: m) {
            auto es = e.second;
            sort(es.begin(), es.end());
            vector<int> v;
            for (auto ee: es) {
                v.push_back(ee.second);
            }
            res.push_back(v);
        }
        return res;
    }
};