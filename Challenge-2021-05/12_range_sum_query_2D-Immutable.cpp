#include "../header.h"

class NumMatrix {
     vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      for (int i = 0; i < m; ++i) {
        v.push_back(vector<int>(n, 0));
      }
      // first row
      int s = 0;
      for (int i = 0; i < n; ++i) {
        s += matrix[0][i];
        v[0][i] = s;
      }
      s = 0;
      for (int j = 0; j < m; ++j) {
        s += matrix[j][0];
        v[j][0] = s;
      }
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1] + matrix[i][j];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      int sub12 = row1 > 0 && col1 > 0 ? v[row1-1][col1-1] : 0;
      int sub1 = col1 > 0 ? v[row2][col1-1] : 0;
      int sub2 = row1 > 0 ? v[row1-1][col2] : 0;
      return v[row2][col2] + sub12 - sub1 - sub2;
    }
};
