#include "../header.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> preSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            preSum[i][0] = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                preSum[i][j] = preSum[i][j-1] + matrix[i][j];
            }
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                mp.clear();
                mp[0] = 1;
                int current = 0;
                for (int k = 0; k < m; ++k) {
                    current += preSum[k][j] - (i > 0 ? preSum[k][i-1]: 0);
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