#include "../header.h"

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if (mines.size() == n * n) {
            return 0;
        }
        if (mines.size() > n * n - 5) {
            return 1;
        }
        int grid[n][n], arm[n][n][4];
        memset(grid, -1, sizeof(grid));
        memset(arm, 0, sizeof(arm));
        for (auto& x: mines) {
            grid[x[0]][x[1]] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    arm[i][j][0] = 1 + ((i > 0) ? arm[i-1][j][0] : 0);
                    arm[i][j][1] = 1 + ((j > 0) ? arm[i][j-1][1] : 0);
                }                
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] != 0) {
                    arm[i][j][2] = 1 + ((i < n - 1) ? arm[i+1][j][2]: 0);
                    arm[i][j][3] = 1 + ((j < n - 1) ? arm[i][j+1][3]: 0);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    int temp = min(min(arm[i][j][0], arm[i][j][1]), min(arm[i][j][2], arm[i][j][3]));
                    res = max(temp, res);
                }                
            }
        }
        return res;
    }
};