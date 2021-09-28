#include "../header.h"

const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, m * n));
        queue<tuple<int, int, int>> q;
        int res = 0;
        q.push({0,0,0});
        visited[0][0] = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto fr = q.front();
                q.pop();
                int x = get<0>(fr), y = get<1>(fr), o = get<2>(fr);
                if (x == m - 1 && y == n - 1) {
                    return res;
                }
                for (int j = 0; j < 4; ++j) {
                    int nx = x + directions[j][0], ny = y + directions[j][1];
                    // out of grid
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                        continue;
                    }
                    int ob = o + grid[nx][ny];
                    // exceed k or current path obstacles are more than previous obstacles
                    if (ob > k || ob >= visited[nx][ny]) {
                        continue;
                    }
                    visited[nx][ny] = ob;
                    q.push({nx, ny, ob});
                }
            }
            ++res;
        }
        return -1;
    }
};