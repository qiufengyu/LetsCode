#include "../header.h"

const int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    res += 1;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int x, int y) {
        grid[x][y] = '0';
        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[d][0];
            int ny = y + dirs[d][1];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                dfs(grid, m, n, nx, ny);
            }
        }
    }
};