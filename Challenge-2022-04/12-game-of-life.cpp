#include "../header.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbor = 0;
                for (int x = max(0, i - 1); x < min(m, i + 2); ++x) {
                    for (int y = max(0, j - 1); y < min(n, j + 2); ++y) {
                        neighbor += (board[x][y] & 1);
                    }
                }
                if (board[i][j] == 1 && (neighbor == 3 || neighbor == 4)) {
                    board[i][j] = (board[i][j] | 2);
                } else if (board[i][j] == 0 && neighbor == 3) {
                    board[i][j] = (board[i][j] | 2);
                }
                // else next board[i][j] = 0
                //the bit at position 31 should be 0 and natually it is
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = (board[i][j] >> 1);
            }
        }        
    }
};