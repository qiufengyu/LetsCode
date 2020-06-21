#include "header.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (height > 0) {
            int width = board[0].size();
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
                        if (board[i][j] == 'O') {
                            update(board, i, j, width, height);
                        }
                    }
                }
            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (board[i][j] == 'T') {
                        board[i][j] = 'O';
                    } else {
                        board[i][j] = 'X';
                    }
                }
            }
        }

    }

    void update(vector<vector<char>>& board, int i, int j, int w, int h) {
        cout << "update " << i << " and " << j << endl;
        board[i][j] = 'T';
        if (i + 1 < h && board[i+1][j] == 'O') {
            update(board, i + 1, j, w, h);
        }
        if (i - 1 >= 0 && board[i-1][j] == 'O') {
            update(board, i - 1, j , w, h);
        }
        if (j - 1 >= 0 && board[i][j-1] == 'O') {
            update(board, i, j - 1, w, h);
        }
        if (j + 1 < w && board[i][j+1] == 'O') {
            update(board, i, j + 1, w, h);
        }
    }
};

int main() {
    vector<vector<char>> board {{'X','O','X','O','X','O'}, {'O','X','O','X','O','X'}, {'X','O','X','O','X','O'}, {'O','X','O','X','O','X'}};
    Solution().solve(board);
    print_vector<char>(board);
    return 0;
}