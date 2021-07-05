#include "../header.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> sum(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            sum[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = j - 1; k <= j + 1; ++k) {
                    if (k >= 0 && k < n) {
                        sum[i][j] = min(sum[i][j], matrix[i][j] + sum[i-1][k]);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, sum[n-1][i]);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
    cout << Solution().minFallingPathSum(matrix) << endl;
    return 0;
}