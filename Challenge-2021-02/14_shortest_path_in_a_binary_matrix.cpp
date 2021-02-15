#include "../header.h"

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int length = grid.size();
      if (grid[length-1][length-1] == 1 || grid[0][0] == 1) {
        return -1;
      }
      if (length == 1) {
          return 1;
      }
      int res = 0;
      bool visited[101][101];
      for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
          visited[i][j] = false;
        }
      }
      visited[0][0] = true;
      int d[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1}, {1, -1}, {1, 0}, {1, 1} };
      queue<pair<int, int>> q;
      q.emplace(0, 0);
      while (!q.empty()) {
        int sz = q.size();
        res++;
        for (int i = 0; i < sz; i++) {
          auto p = q.front();
          q.pop();
          for (int j = 0; j < 8; j++) {
            int x = p.first + d[j][0];
            int y = p.second + d[j][1];
            if (x >= 0 && y >= 0 && x < length && y < length && grid[x][y] == 0 && !visited[x][y]) {
              if (x == length - 1 && y == length - 1) {
                return res + 1;
              }
              visited[x][y] = true;
              q.emplace(x, y);
            }
          }
        }
      }
      return -1;
    }
};