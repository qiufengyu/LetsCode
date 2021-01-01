#include "../header.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        int r = m + n - 1;
        for (int i = 0; i < r; i++) {
            if (i % 2 == 0) { // up
                for (int j = i; j >= 0; j--) {
                    if (j < m && i - j < n) res.push_back(matrix[j][i-j]);
                }
            } else { // down
                for (int j = i; j >= 0; j--) {
                    if (i - j < m && j < n) res.push_back(matrix[i-j][j]);
                }
            }
        }
        return res;
    }
};
