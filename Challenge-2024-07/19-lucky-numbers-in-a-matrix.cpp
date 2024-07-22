#include "../header.h"

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> cst, rst;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            rst.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx, matrix[i][j]);
            }
            cst.insert(mx);
        }
        vector<int> res(1);
        auto it = set_intersection(cst.begin(), cst.end(), rst.begin(), rst.end(), res.begin());
        res.resize(it - res.begin());
        return res;
    }
};