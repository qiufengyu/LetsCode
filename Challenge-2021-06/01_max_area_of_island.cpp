#include "../header.h"

int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int res = 0, current = 0;
      const int m = grid.size(), n = grid[0].size();
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j]) {
            current = 1;
            grid[i][j] = 0;
            dfs(grid, current, m, n, i, j);
            res = max(res, current);
          }
        }
      }
      return res;        
    }

    void dfs(vector<vector<int>>& grid, int& current, const int m, const int n, int i, int j) {
      for (int d = 0; d < 4; ++d) {
        int x = i + directions[d][0], y = j + directions[d][1];
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
          grid[x][y] = 0;
          ++current;
          dfs(grid, current, m, n, x, y);
        }
      }
    }
};

int main() {
  vector<vector<int>> grid {
    {0,0,0,0,0,0,0,0,0,0,0,0,0}
  };
  int res = Solution().maxAreaOfIsland(grid);
  cout << res << endl;
  return 0;
}