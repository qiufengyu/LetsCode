#include "../header.h"

const int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                        {0, -1}, {0, 1},
                        {1, -1}, {1, 0}, {1, 1}};

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                int mx = grid[i][j];
                for (int k = 0; k < 8; k++) {
                    mx = max(mx, grid[i+dirs[k][0]][j+dirs[k][1]]);
                }
                res[i-1][j-1] = mx;
            }
        }
        return res;
    }
};