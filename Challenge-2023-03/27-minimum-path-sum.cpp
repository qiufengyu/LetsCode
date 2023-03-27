#include "../header.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        // first row
        for (int i = 1; i < n; ++i) {
            dist[0][i] = dist[0][i-1] + grid[0][i];
        }
        // first col
        for (int i = 1; i < m; ++i) {
            dist[i][0] = dist[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dist[i][j] = min(dist[i-1][j], dist[i][j-1]) + grid[i][j];
            }
        }
        return dist[m-1][n-1];
    }
};