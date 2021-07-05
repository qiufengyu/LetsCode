#include "../header.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        int total = m * n;
        if (total != r * c) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        int i = 0;
        while (i < total) {
            res[i/c][i%c] = mat[i/n][i%n];
            i++;
        }
        return res;
    }
};