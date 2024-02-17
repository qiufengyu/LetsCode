#include "../header.h"

const int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        // edge case
        if (q.size() == n * n || q.empty()) {
            return -1;
        }
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                auto r = q.front();
                int x = r.first, y = r.second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + directions[i][0], ny = y + directions[i][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                --sz;
            }
            ++res;
        }
        return res - 1;
    }
};