#include "../header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        for (int depth = 1; depth <= (n + 1) / 2; ++depth) {
            // 1. top row, left to right
            for (int i = depth - 1; i < n - depth; ++i) {
                res[depth - 1][i] = num;
                num++;
            }
            // 2. last column, top to bottom
            for (int j = depth - 1; j < n - depth; ++j) {
                res[j][n - depth] = num;
                num++;
            }
            // 3. last row, right to left
            for (int i = n - depth; i >= depth; --i) {
                res[n - depth][i] = num;
                num++;
            }
            // 4. first column, bottomn to top
            for (int j = n - depth; j >= depth; --j) {
                res[j][depth - 1] = num;
                num++;
            }
        }
        if (n % 2 == 1) {
            res[n/2][n/2] = n * n;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = Solution().generateMatrix(n);
    print_vector<int>(res);
    return 0;
}