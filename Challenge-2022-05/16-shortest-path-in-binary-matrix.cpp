#include "../header.h"

const int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 0) {
            int m = grid.size();
            vector<vector<bool>> visited(m, vector<bool>(m, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            int res = 1;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    auto p = q.front();
                    q.pop();
                    if (p.first == m - 1 && p.second == m - 1) {
                        return res;
                    }
                    for (int j = 0; j < 8; ++j) {
                        int x = p.first + d[j][0], y = p.second + d[j][1];
                        if (x >= 0 && x < m && y >= 0 && y < m && !visited[x][y] && grid[x][y] == 0) {
                            visited[x][y] = true;
                            q.push({x, y});
                        }
                    }
                }
                ++res;
            }
            return -1;
        }
        return -1;
    }
};