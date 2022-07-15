#include "../header.h"

const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0, current = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, current, res);
                }
                current = 0;
            }
        }
        return res;        
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& current, int& res) {
        ++current;
        res = max(res, current);
        grid[i][j] = 0;
        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d][0], y = j + dirs[d][1];
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                dfs(grid, x, y, m, n, current, res);
            }
        }
    }
};