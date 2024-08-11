#include "../header.h"

int const dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        // get componets
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int components = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (!visited[i][j])) {
                    components++;
                    dfs(grid, visited, i, j, m, n);
                }
            }
        }
        if (components == 1) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        components = 0;
                        grid[i][j] = 0;
                        for (int k = 0; k < m; k++) {
                            fill(visited[k].begin(), visited[k].end(), false);
                        }
                        for (int ii = 0; ii < m; ii++) {
                            for (int jj = 0; jj < n; jj++) {
                                if (grid[ii][jj] == 1 && (!visited[ii][jj])) {
                                    components++;
                                    dfs(grid, visited, ii, jj, m, n);
                                }
                            }
                        }
                        if (components != 1) {
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
            return 2;
        }
        return 0;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, const int m, const int n) {
        visited[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int x = i + dirs[d][0], y = j + dirs[d][1];
            if (x >= 0 && x < m && y >= 0 && y < n && (!visited[x][y]) && grid[x][y] == 1) {
                dfs(grid, visited, x, y, m, n);
            }
        }
    }
};
