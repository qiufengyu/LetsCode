#include "../header.h"

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> tree;
        // count_i: the number of nodes in the tree rooted by node_i
        vector<int> count(n, 1), res(n, 0);
        for (auto const& e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs1(0, -1, tree, count, res, n);
        dfs2(0, -1, tree, count, res, n);
        return res;
    }

    void dfs1(int node, int parent, unordered_map<int, vector<int>>& tree,
              vector<int>& count, vector<int>& res, const int n) {
        for (auto const& nbr: tree[node]) {
            if (nbr != parent) {
                dfs1(nbr, node, tree, count, res, n);
                count[node] += count[nbr];
                res[node] += (count[nbr] + res[nbr]);
            }
        }
    }

    void dfs2(int node, int parent, unordered_map<int, vector<int>>& tree,
              vector<int>& count, vector<int>& res, const int n) {
        for (auto const& nbr: tree[node]) {
            if (nbr != parent) {
                // - count[nbr]: the sub nodes should not go over parent node
                // n - count[nbr]: the rest nodes will add a length from the nbr to the parent
                res[nbr] = res[node] - count[nbr] + n - count[nbr];
                dfs2(nbr, node, tree, count, res, n);
            }            
        }
    }
};