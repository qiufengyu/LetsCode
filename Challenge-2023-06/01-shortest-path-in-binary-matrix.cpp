#include "../header.h"

int const dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int res = 0, x= 0, y = 0;
        while (!q.empty()) {
            ++res;
            int sz = q.size();
            while (sz > 0) {
                auto f = q.front();
                q.pop();
                if (f.first == n - 1 && f.second == n - 1) {
                    return res;
                }
                for (int i = 0; i < 8; ++i) {
                    x = f.first + dirs[i][0];
                    y = f.second + dirs[i][1];
                    if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
                --sz;
            }            
        }
        return -1;
    }
};