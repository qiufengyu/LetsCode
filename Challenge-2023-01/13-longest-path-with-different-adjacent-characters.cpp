#include "../header.h"

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        // 1 node only, will not build the graph or do DFS below
        int res = 1;
        int n = parent.size();
        unordered_map<int, vector<int>> graph;
        for (int i = 1; i < n; ++i) {
            if (graph.count(parent[i])) {
                graph[parent[i]].push_back(i);
            } else {
                graph[parent[i]] = {i};
            }
        }
        dfs(graph, s, 0, res);
        return res;
    }

    int dfs(unordered_map<int, vector<int>>& graph, string const& s, int node, int& res) {
        // leaf node
        if (graph.count(node) == 0) {
            return 1;
        }
        int res1 = 0, res2 = 0;
        for (int const nbr: graph[node]) {
            int nbrRes = dfs(graph, s, nbr, res);
            if (s[nbr] == s[node]) {
                continue;
            }
            if (nbrRes > res1) {
                res2 = res1;
                res1 = nbrRes;
            } else if (nbrRes > res2) {
                res2 = nbrRes;
            }
        }
        // current node + two paths from this node
        res = max(res, 1 + res1 + res2);
        // return to parent the current max single path
        return res1 + 1;
    }
};
