#include "../header.h"

int const M = 1000000007;

const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline bool inGrid(int m, int n, int x, int y) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> grid1(m, vector<int>(n, 0)), grid2(m, vector<int>(n, 0));
        grid1[startRow][startColumn] = 1;
        int res = 0;
        while (maxMove) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid1[i][j] > 0) {
                        for (int d = 0; d < 4; d++) {
                            int x = i + directions[d][0], y = j + directions[d][1];
                            if (inGrid(m, n, x, y)) {
                                grid2[x][y] = (grid2[x][y] + grid1[i][j]) % M;
                            } else {
                                res = (res + grid1[i][j]) % M;
                            }
                        }
                    }
                }
            }
            swap(grid1, grid2);
            // reset grid2 to calculate all next round
            for (size_t i = 0; i < m; ++i) {
                fill(grid2[i].begin(), grid2[i].end(), 0);
            }
            maxMove--;
        }
        return res;
    }
};