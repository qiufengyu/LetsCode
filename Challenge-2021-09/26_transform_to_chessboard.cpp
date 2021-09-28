#include "../header.h"

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) {
                    return -1;
                }
            }
        }
        int rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
        for (int i = 0; i < n; ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowDiff += (board[0][i] != i % 2);
            colDiff += (board[i][0] != i % 2 );
        }
        if (n % 2 == 0) {
            if (rowSum * 2 == n && colSum * 2 == n) {
                return (min(rowDiff, n - rowDiff) + min(colDiff, n - colDiff)) / 2;
            }
            return -1;
        }
        else {
            if ((rowSum == n / 2 || rowSum == n / 2 + 1) && (colSum == n / 2 || colSum == n / 2 + 1)) {
                int rowRes = rowSum * 2 > n ? n - rowDiff : rowDiff;
                int colRes = colSum * 2 > n ? n - colDiff : colDiff;
                return (rowRes + colRes) / 2;
            }
            return -1;
        }
        return -1;
    }
};