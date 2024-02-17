#include "../header.h"

const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((!visited[i][j]) && grid[i][j] == 0 && bfs(grid, m, n, i, j, visited)) {
                    visited[i][j] = true;
                    ++res;
                }
            }
        }
        return res;
    }

    bool bfs(vector<vector<int>>& grid, const int m, const int n, int i, int j, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});       
        bool closed = true;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                auto g = q.front();
                q.pop();
                i = g.first;
                j = g.second;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dirs[d][0], nj = j + dirs[d][1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                        closed = false;
                    } else {
                        if (grid[ni][nj] == 0 && (!visited[ni][nj])) {
                            q.push({ni, nj});
                            // avoid duplicated ni and nj in the same level
                            visited[ni][nj] = true;
                        }
                    }
                }
                --sz;
            }
        }
        return closed;
    }
};