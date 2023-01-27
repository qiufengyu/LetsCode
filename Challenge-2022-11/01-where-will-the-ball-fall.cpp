#include "../header.h"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (res[j] == -1) {
                    continue;
                }
                if (res[j] == 0) {
                    if (grid[i][0] == -1) {
                        res[j] = -1;
                    } else {
                        if (1 < n && grid[i][1] == 1) {
                            res[j] = 1;
                        } else {
                            res[j] = -1;
                        }
                    }
                } else if (res[j] == n - 1) {
                    if (grid[i][n-1] == 1) {
                        res[j] = -1;
                    } else {
                        if (n - 2 >= 0 && grid[i][n-2] == -1) {
                            res[j] = n - 2;
                        } else {
                            res[j] = -1;
                        }
                    }
                } else {
                    int x = res[j];
                    if (grid[i][x] == 1) {
                        if (grid[i][x+1] == 1) {
                            res[j] = x + 1;
                        } else {
                            res[j] = -1;
                        }
                    } else {
                        if (grid[i][x-1] == -1) {
                            res[j] = x - 1;
                        } else {
                            res[j] = -1;
                        }
                    }
                }
            }
        }
        return res;
    }
};