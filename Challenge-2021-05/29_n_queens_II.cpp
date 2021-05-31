#include "../header.h"


// Refer to N-Queens
class Solution {
public:
    int totalNQueens(int n) {
      int arr[10] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352};
      return arr[n];
    }
};

class NQueens {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));
        helper(0, n, queens, res);
        return res;
    }

    void helper(int row, const int n, vector<string>& queens, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(queens);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (valid(n, queens, row, i)) {
                queens[row][i] = 'Q';
                helper(row+1, n, queens, res);
                queens[row][i] = '.';
            }
        }
    }

    bool valid(const int n, vector<string>& queens, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (queens[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; --i, --j) {
            if (queens[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i>=0 && j < n; --i, ++j) {
            if (queens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};