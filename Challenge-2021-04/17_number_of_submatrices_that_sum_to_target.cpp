#include "../header.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
          return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> preSum(m, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            preSum[i][j+1] = matrix[i][j] + preSum[i][j];
          }
        }
        // to calculate with preSum
        for (int i = 0; i < n; ++i) {
          for (int j = i; j < n; ++j) {
            int current = 0;
            unordered_map<int, int> mp;
            mp[0] = 1;
            for (int k = 0; k < m; ++k) {
              current += preSum[k][j+1] - preSum[k][i];
              if (mp.count(current - target)) {
                res += mp[current - target];
              }
              ++mp[current];
            }
          }
        }
        return res;
    }
};