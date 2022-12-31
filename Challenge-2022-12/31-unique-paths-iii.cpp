#include "../header.h"

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startx = 0, starty = 0, zeros = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++zeros;
                } else if (grid[i][j] == 1) {
                    startx = i;
                    starty = j;
                }
            }
        }
        return dfs(grid, startx, starty, zeros, m, n);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, const int zeros, const int m, const int n) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1)  {
            return 0;
        }
        if (grid[x][y] == 2) {
            return zeros == 0;
        }
        grid[x][y] = -1;
        int nxt = dfs(grid, x + 1, y, zeros - 1, m, n) + 
                  dfs(grid, x - 1, y, zeros - 1, m, n) + 
                  dfs(grid, x, y + 1, zeros - 1, m, n) + 
                  dfs(grid, x, y - 1, zeros - 1, m, n);
        grid[x][y] = 0;
        return nxt;
    }
};