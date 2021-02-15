#include "../header.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      int nodes[101];
      for (int i = 0; i < 101; i++) nodes[i] = 0;
      for (int i = 0; i < n; i++) {
        if (nodes[i] == 0) {
          nodes[i] = 1;
          queue<int> q;
          q.push(i);
          while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto neighbor: graph[t]) {
              if (nodes[neighbor] == nodes[t]) {
                return false;
              }
              if (nodes[neighbor] == 0) {
                nodes[neighbor] = -1 * nodes[t];
                q.push(neighbor);
              }
            }
          }
        }
      }
    return true;
  }
};