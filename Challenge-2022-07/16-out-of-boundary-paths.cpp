#include "../header.h"


int const M = 1000000007;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1,0}};

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        int res = 0;
        for (int t = 0; t < maxMove; ++t) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] != 0) {
                        for (int d = 0; d < 4; ++d) {
                            int x = i + dirs[d][0], y = j + dirs[d][1];
                            if (x < 0 || y < 0 || x >= m || y >= n) {
                                res = (res + dp[i][j]) % M;
                            } else {
                                temp[x][y] = (temp[x][y] + dp[i][j]) % M;
                            }
                        }
                    }
                }
            }
            dp = temp;
        }
        return res;
    }
};