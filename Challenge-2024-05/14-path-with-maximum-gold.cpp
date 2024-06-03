#include "../header.h"

int const dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    visited[i][j] = true;
                    dfs(grid, visited, m, n, i, j, res, 0);
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int const m, int const n, int i, int j, int& res, int tmp) {
        tmp += grid[i][j];
        res = max(res, tmp);
        for (int d = 0; d < 4; d++) {
            int x = i + dirs[d][0], y = j + dirs[d][1];
            if (x >= 0 && x < m && y >= 0 && y < n && (!visited[x][y]) && grid[x][y] > 0) {
                visited[x][y] = true;
                dfs(grid, visited, m, n, x, y, res, tmp);
                visited[x][y] = false;
            }
        }
    }
};