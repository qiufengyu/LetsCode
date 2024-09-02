#include "../header.h"

int const dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    vector<pair<int, int>> v;
                    dfs(grid2, i, j, m, n, v);
                    bool covered = true;
                    for (auto const& p: v) {
                        if (grid1[p.first][p.second] != 1) {
                            covered = false;
                            break;
                        }
                    }
                    if (covered) {
                        res++;
                    }
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<pair<int, int>>& v) {
        v.push_back({i, j});
        grid[i][j] = 0;
        for (int d = 0; d < 4; d++) {
            int x = i + dirs[d][0], y = j + dirs[d][1];
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                dfs(grid, x, y, m, n, v);
            }
        }
    }
};