#include "../header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int path[101][101];
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            path[i][j] = 0;
          }
        }
        path[0][0] = 1 - obstacleGrid[0][0];
        // first row, column
        for (int i = 1; i < n; ++i) {
          if (obstacleGrid[0][i]) {
              path[0][i] = 0;
          } else {
            path[0][i] = path[0][i-1];
          }
        }
        for (int i = 1; i < m; ++i) {
          if (obstacleGrid[i][0]) {
            path[i][0] = 0;
          } else {
            path[i][0] = path[i-1][0];
          }
        }
        if (m == 1 && n == 1) {
            return 1 - obstacleGrid[0][0];
        }
        for (int i = 1; i < m; ++i) {
          for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j]) {
              path[i][j] = 0;
            } else {
              path[i][j] = path[i][j-1] + path[i-1][j];
            }
          }
        }
        return path[m-1][n-1];
    }
};
