#include "../header.h"

class NumMatrix {
    vector<vector<int>> sum;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};
