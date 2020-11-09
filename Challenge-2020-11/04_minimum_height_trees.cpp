#include "../header.h"
#include <numeric>

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        queue<int> q;
        vector<int> res;
        if (n == 1) {
            return {0};
        } else if (n == 2) {
            return {0,1};
        }
        for (auto edge: edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        for (int i = 0; i < n; i++) {
                if (g[i].size() == 1) {
                    q.push(i);
                }
            }
        while (n > 2) {
            int sz = q.size();
            n -= q.size();
            vector<int> leaves;
            // find all leaf nodes
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                for (auto neighbor: g[node]) {
                    g[neighbor].erase(node);
                    if (g[neighbor].size() == 1) {
                        q.push(neighbor);
                    }
                } 
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

