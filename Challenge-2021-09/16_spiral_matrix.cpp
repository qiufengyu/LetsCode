#include "../header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        // 1 <= m, n <= 10
        int m = matrix.size(), n = matrix[0].size();
        int R = 1 + min(m / 2, n / 2);
        int r = 0;
        while (r < R) {
            // row r
            for (int j = r; j < n - r; ++j) {
                res.push_back(matrix[r][j]);
            }
            // column: n - r
            for (int i = r + 1; i < m - r; ++i) {
                res.push_back(matrix[i][n-r-1]);
            }
            // row: m - r
            for (int j = n - r - 2; j >= r; --j) {
                res.push_back(matrix[m-r-1][j]);
            }
            // column: r
            for (int i = m - r - 2; i > r; --i) {
                res.push_back(matrix[i][r]);
            }
            r++;
        }
        res.resize(m * n);
        return res;
    }
};

int main() {
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto res = Solution().spiralOrder(matrix);
    print_vector<int>(res);
    return 0;
}