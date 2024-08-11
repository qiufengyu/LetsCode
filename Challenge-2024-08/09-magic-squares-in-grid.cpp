#include "../header.h"

class Solution {
    bool magic(vector<vector<int>>& grid, int i, int j) {
        vector<int> exists(10, 0);
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (grid[i-1+x][j-1+y] <= 0 || grid[i-1+x][j-1+y] > 9) {
                    return false;
                }
                exists[grid[i-1+x][j-1+y]] = 1;
            }
        }
        if (accumulate(exists.begin(), exists.end(), 0) != 9) {
            return false;
        }
        // row && col
        for (int k = -1; k <= 1; k++) {
            if ((grid[i+k][j-1] + grid[i+k][j] + grid[i+k][j+1] != 15) || (grid[i-1][j+k] + grid[i][j+k] + grid[i+1][j+k] != 15)) {
                return false;
            }
        }
        return (grid[i-1][j-1] + grid[i+1][j+1] == 10) && (grid[i-1][j+1] + grid[i+1][j-1] == 10);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 5 && magic(grid, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
};