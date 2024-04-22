#include "../header.h"

const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int ix = i + dirs[d][0], jy = j + dirs[d][1];
                        if (ix < 0 || jy < 0 || ix >= m || jy >= n) {
                            res++;
                        } else if (grid[ix][jy] == 0) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};