#include "../header.h"

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size(), res = 0;
        int x = entrance[0], y = entrance[1];
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                auto p = q.front();
                q.pop();
                x = p.first;
                y = p.second;
                for (int i = 0; i < 4; ++i) {
                    int xx = x + dirs[i][0], yy = y + dirs[i][1];
                    // simple BFS, but not judging here will cause TLE on leetcode
                    if (xx < 0 || yy < 0 || xx >= m || yy >= n || maze[xx][yy] == '+') {
                        continue;
                    }
                    maze[xx][yy] = '+';
                    if (xx == 0 || yy == 0 || xx == m - 1 || yy == n - 1) {
                        if (xx != entrance[0] || yy != entrance[1]) {
                            return res + 1;
                        }
                    }
                    q.push({xx, yy});
                }
                --sz;
            }
            ++res;
        }
        return -1;
    }
};
