#include "../header.h"

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      vector<vector<int>> res;
      if (n < 1) {
        return res;
      }
      vector<vector<int>> graph(n, vector<int>());
      for (auto connect: connections) {
        graph[connect[0]].push_back(connect[1]);
        graph[connect[1]].push_back(connect[0]);
      }
      vector<int> depth(n, -1);
      vector<int> low(n, 0);
      int current = 0;
      for (int i = 0; i < n; ++i) {
        if (depth[i] == -1) {
          dfs(i, low, depth, graph, res, -1, current);
        }
      }
      return res;
    }

    void dfs(int u, vector<int>& low, vector<int>& depth, vector<vector<int>>& graph, vector<vector<int>>& res, int parent, int& current) {
      ++current;
      depth[u] = current;
      low[u] = current;
      vector<int> neighbors = graph[u];
      for (int v: neighbors) {
        if (v == parent) {
          continue;
        }
        if (depth[v] == -1) {
          dfs(v, low, depth, graph, res, u, current);
          low[u] = min(low[u], low[v]);
          if (low[v] > depth[u]) {
            res.push_back({u, v});
          }
        }
        else {
          low[u] = min(low[u], depth[v]);
        }
      }
    }
};