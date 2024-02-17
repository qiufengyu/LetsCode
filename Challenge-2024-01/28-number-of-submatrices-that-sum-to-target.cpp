#include "../header.h"

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for (int r = 0; r < m; r++) {
                    sum += (matrix[r][j] - (i == 0 ? 0 : matrix[r][i-1]));
                    int rest = sum - target;
                    if (mp.count(rest)) {
                        res += mp[rest];
                    }
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};