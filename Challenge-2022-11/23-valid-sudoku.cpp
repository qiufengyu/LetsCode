#include "../header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool bitsRow[9] = {false}, bitsCol[9] = {false};
        // all row + columns
        for (int i = 0; i < 9; ++i) {
            memset(bitsRow, 0, sizeof(bitsRow));
            memset(bitsCol, 0, sizeof(bitsCol));
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int idxCol = board[i][j] - '1';
                    if (bitsRow[idxCol]) {
                        return false;
                    } else {
                        bitsRow[idxCol] = true;
                    }
                }
                if (board[j][i] != '.') {
                    int idxRow = board[j][i] - '1';
                    if (bitsCol[idxRow]) {
                        return false;
                    } else {
                        bitsCol[idxRow] = true;
                    }
                }
            }            
        }
        // sub grids
        for (int i = 0; i < 9; ++i) {
            int rStart = i / 3 * 3, cStart = (i % 3) * 3;
            memset(bitsRow, 0, sizeof(bitsRow));
            for (int j = rStart; j < 3 + rStart; ++j) {
                for (int k = cStart; k < 3 + cStart; ++k) {
                    if (board[j][k] != '.') {
                        int t = board[j][k] - '1';
                        if (bitsRow[t]) {
                            return false;
                        } else {
                            bitsRow[t] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
