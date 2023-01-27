#include "../header.h"

class Solution {
    vector<vector<int>> tree;
    vector<int> count, res;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.assign(n, 0);
        count.assign(n, 1);
        for (auto const& edge: edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }

    void dfs1(int root, int prev) {
        for (auto const& i: tree[root]) {
            if (i != prev) {
                dfs1(i, root);
                count[root] += count[i];
                res[root] += (res[i] + count[i]);
            }            
        }
    }

    void dfs2(int root, int prev) {
        for (auto const& i: tree[root]) {
            if (i != prev) {
                // res[root] - count[i]: the subtree under i, decrease from root by 1
                // count.size() - count[i]: the other part in the tree, need to increase 1 from root
                res[i] = res[root] - count[i] + (count.size() - count[i]);
                dfs2(i, root);
            }
        }
    }
};