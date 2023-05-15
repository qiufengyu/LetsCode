#include "../header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int r = (1 + min(m, n)) / 2;
        vector<int> res;
        for (int i = 0; i < r; ++i) {
            // 1st row
            for (int j = i; j < n - i; ++j) {
                res.push_back(matrix[i][j]);
                cout << matrix[i][j] << endl;
            }
            // last col: n - i - 1
            for (int j = i + 1; j < m - i; ++j) {
                cout << "last row: " << m - i - 1 << endl;
                res.push_back(matrix[j][n - i - 1]);
            }
            // last row: m - i - 1
            for (int j = n - 2 - i; j >= i; --j) {
                res.push_back(matrix[m - i - 1][j]);
                cout << matrix[m - i - 1][j] << endl;
            }
            // 1st col
            for (int j = m - i - 2; j > i; --j) {
                res.push_back(matrix[j][i]);
                cout << matrix[j][i] << endl;
            }
        }
        res.resize(m * n);
        return res;        
    }
};

int main() {
    vector<vector<int>> mat{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    auto res = Solution().spiralOrder(mat);
    print_vector<int>(res);
    return 0;
}