#include "../header.h"

int const dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int step = 1, cells = rows * cols;
        int direction = 0;
        int i = rStart, j = cStart;
        res.push_back({i, j});
        while (cells > 1) {
            auto d = dirs[direction % 4];
            int l = step;
            while (l > 0) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    res.push_back({ni, nj});
                    cells--;
                }
                l--;
                i = ni;
                j = nj;
            }
            direction = direction + 1;
            if (direction % 2 == 0) {
                step++;
            }
        }
        return res;
    }
};