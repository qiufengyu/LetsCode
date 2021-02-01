#include "../header.h"

typedef pair<int, int> Pair;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      const int directions[5] = {0, 1, 0, -1, 0};
      const int rows = heights.size();
      const int cols = heights[0].size();
      priority_queue<Pair, vector<Pair>, greater<Pair>> q;
      vector<int> dist(rows * cols, 1e6);
      dist[0] = 0;
      q.push({0, 0});
      while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (p.second == rows * cols - 1) {
          return p.first;
        }
        if (p.first > dist[p.second]) {
          continue;
        }
        int x = p.second % cols;
        int y = p.second / cols;
        for (int i = 0; i < 4; i++) {
          int dx = x + directions[i];
          int dy = y + directions[i + 1];
          if (dx < 0 || dx == cols || dy < 0 || dy == rows) {
            continue;
          }
          int v = dy * cols + dx;
          int c = abs(heights[y][x] - heights[dy][dx]);
          if (max(c, p.first) >= dist[v]) {
            continue;
          }
          dist[v] = max(c, p.first);
          q.push({dist[v], v});
        }
      }
      return -1;
    }
};