#include "../header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // all rows & columns
        bool bits1[9];
        bool bits2[9];
        for (int i = 0; i < 9; ++i) {
            memset(bits1, 0, sizeof(bits1));
            memset(bits2, 0, sizeof(bits2));
            for (int j = 0; j < 9; ++j) {
                char c1 = board[i][j], c2 = board[j][i];
                if (c1 != '.') {
                    if (bits1[c1 - '1']) {
                        return false;
                    }
                    bits1[board[i][j] - '1'] = true;
                }
                if (c2 != '.') {
                    if (bits2[board[j][i] - '1']) {
                        return false;
                    }                    
                    bits2[board[j][i] - '1'] = true;
                }
            }
        }
        // sub grids
        for (int i = 0; i < 9; ++i) {
            int gridR = i / 3 * 3, gridC = i % 3 * 3;
            memset(bits1, 0, sizeof(bits1));
            for (int k = gridR; k < gridR + 3; ++k) {
                for (int l = gridC; l < gridC + 3; ++l) {
                    char c = board[k][l];
                    if (c != '.') {
                        if (bits1[board[k][l] - '1']) {
                            return false;
                        }
                        bits1[board[k][l] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    cout << Solution().isValidSudoku(board) << endl;
    return 0;
}