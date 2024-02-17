#include "../header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r = 1 + n / 2;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int number = 1;
        for (int i = 0; i < r; ++i) {
            // 1st row
            for (int j = i; j < n - i; ++j) {
                res[i][j] = number++;
            }
            // last col: n - i - 1
            for (int j = i + 1; j < n - i; ++j) {
                res[j][n - i - 1] = number++;
            }
            // last row: m - i - 1
            for (int j = n - 2 - i; j >= i; --j) {
                res[n - i - 1][j] = number++;
                
            }
            // 1st col
            for (int j = n - i - 2; j > i; --j) {
               res[j][i] = number++;
            }
        }
        return res;        
    }
};

int main() {
    auto res = Solution().generateMatrix(3);
    print_vector<int>(res);
    return 0;
}