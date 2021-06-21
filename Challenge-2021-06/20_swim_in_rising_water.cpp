#include "../header.h"

const int directions[4][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0, right = n * n - 1;
        while (left < right) {
          int mid = (left + right) / 2;
          vector<vector<bool>> visited(n, vector<bool>(n, false));
          if (dfs(grid, 0, 0, visited, mid, n)) {
            right = mid;
          } else {
            left = mid + 1;
          }
        }
        return left;
    }

    bool dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, int mid, const int n) {
      if (mid < grid[x][y]) {
        return false;
      }
      visited[x][y] = true;
      if (x == n - 1 && y == n - 1) {
        return true;
      }
      for (int i = 0; i < 4; ++i) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >=0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && dfs(grid, x, y, visited, mid, n)) {
          return true;
        }
      }
      return false;
    }
};