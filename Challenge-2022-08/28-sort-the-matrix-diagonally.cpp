#include "../header.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<priority_queue<int>> temp(m + n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i - j + n].push(-mat[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = -temp[i-j+n].top();
                temp[i - j + n].pop();
            }
        }
        return mat;
    }
};