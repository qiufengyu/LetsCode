#include "../header.h"

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0LL;
        int m = matrix.size(), n = matrix[0].size();
        int x = INT_MAX, count = 0;
        bool flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    count++;
                    res += (long long)(-matrix[i][j]);
                    x = min(x, -matrix[i][j]);
                } else if (matrix[i][j] == 0) {
                    flag = true;
                } else {
                    res += (long long)(matrix[i][j]);
                    x = min(x, matrix[i][j]);
                }
            }
        }
        if ((count % 2) == 1) {
            if (!flag) {
                res -= (2 * x);
            }            
        }
        return res;
    }
};