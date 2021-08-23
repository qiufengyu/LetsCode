#include "../header.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9));
        vector<vector<int>> cols(9, vector<int>(9));
        vector<vector<int>> boxes(9, vector<int>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    int n = c - '1';
                    rows[i][n] = 1;
                    cols[j][n] = 1;
                    boxes[i / 3 * 3 + j / 3][n] = 1;
                }
            }
        }
        fill(board, rows, cols, boxes, 0, 0);
    }

    bool fill(vector<vector<char>>& board,
              vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& boxes,
              int x, int y) {
        if (x >= 9 || y >= 9) {
            return true;
        }
        int ny = (y + 1) % 9;
        int nx = ny == 0 ? x + 1 : x;
        if (board[x][y] != '.') {
            return fill(board, rows, cols, boxes, nx, ny);
        }
        for (int z = 0; z < 9; ++z) {
            int bx = x / 3, by = y / 3;
            int boxIndex = bx * 3 + by;
            if (!rows[x][z] && !cols[y][z] && !boxes[boxIndex][z]) {
                board[x][y] = z + '1';
                rows[x][z] = 1;
                cols[y][z] = 1;
                boxes[boxIndex][z] = 1;
                if (fill(board, rows, cols, boxes, nx, ny)) {
                    return true;
                }
                board[x][y] = '.';
                rows[x][z] = 0;
                cols[y][z] = 0;
                boxes[boxIndex][z] = 0;
            }
        }
        return false;
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
    Solution s;
    s.solveSudoku(board);
    print_vector<char>(board);
    return 0;
}