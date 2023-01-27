#include "../header.h"

const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }
        vector<vector<int>> visited(m, vector<int>(n, m * n));
        queue<tuple<int, int, int>> q;
        int res = 0;
        q.push({0, 0, 0});
        visited[0][0] = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                auto t = q.front();
                q.pop();
                int x = get<0>(t), y = get<1>(t), o = get<2>(t);
                if (x == m - 1 && y == n - 1) {
                    return res;
                }
                for (int d = 0; d < 4; ++d) {
                    int xx = x + directions[d][0], yy = y + directions[d][1];
                    if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
                        continue;
                    }
                    int oo = o + grid[xx][yy];
                    if (oo > k || oo >= visited[xx][yy]) {
                        continue;
                    }
                    visited[xx][yy] = oo;
                    q.push({xx, yy, oo});
                }
                --sz;
            }
            ++res;
        }
        return -1;
    }
};