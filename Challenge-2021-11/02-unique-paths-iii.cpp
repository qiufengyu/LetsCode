#include "../header.h"

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        int n = 1;
        int gm = grid.size();
        int gn = grid[0].size();
        for (int i = 0; i < gm; i++) {
            for (int j = 0; j < gn; j++) {
                if (grid[i][j] == 0) {
                    n++;
                }
                else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        return dfs(grid, gm, gn, x, y, n);
    }
    int dfs(vector<vector<int>>& grid, const int gm, const int gn, int x, int y, int n) {
        if (x < 0 || y < 0 || x >= gm || y >= gn || grid[x][y] == -1) {
            return 0;
        }
        if (grid[x][y] == 2) {
            return n == 0;
        }
        grid[x][y] = -1;
        int res = dfs(grid, gm, gn, x+1, y, n-1) +
                  dfs(grid, gm, gn, x, y+1, n-1) +
                  dfs(grid, gm, gn, x-1, y, n-1) +
                  dfs(grid, gm, gn, x, y-1, n-1);
        grid[x][y] = 0;
        return res;
    }
};