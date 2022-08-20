#include "../header.h"

class Solution {
    vector<int> rank{0}, low{0};
    int current = 1;
    vector<vector<int>> res;
    unordered_map<int, vector<int>> graph;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n < 1) {
            return res;
        }
        for (auto connection: connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        dfs(0, -1);
        return res;
    }

    void dfs(int u, int v) {
        rank[u] = low[u];
        low[u] = current;
        ++current;
        for (int neighbor: graph[u]) {
            if (rank[neighbor] == 0) {
                dfs(neighbor, u);
                low[u] = min(low[u], low[neighbor]);
            } else if (neighbor != v) {
                low[u] = min(low[u], rank[neighbor]);
            }
            if (low[neighbor] > rank[u]) {
                res.push_back({u, neighbor});
            } 
        }
    }
};