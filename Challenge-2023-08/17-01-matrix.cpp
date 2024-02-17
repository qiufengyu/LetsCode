#include "../header.h"

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<int> q;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push(10000 * i + j);
                } else {
                    res[i][j] = -1;
                }
            }
        }
        int depth = 0;
        while (!q.empty()) {
            int sz = q.size();
            depth++;
            while (sz) {
                int idx = q.front();
                q.pop();
                int x = idx / 10000, y = idx % 10000;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0], ny = y + dirs[i][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == 1 && res[nx][ny] == -1) {
                        res[nx][ny] = depth;
                        q.push(nx * 10000 + ny);
                    }
                }
                --sz;
            }
        }
        return res;
    }
};