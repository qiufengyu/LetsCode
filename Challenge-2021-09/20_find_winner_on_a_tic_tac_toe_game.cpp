#include "../header.h"

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        bool first = true;
        for (auto const& move: moves) {
            board[move[0]][move[1]] = first ? 'X' : 'O';
            first = !first;
        }
        // check row, col
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X') {
                    return "A";
                } else if (board[i][0] == 'O') {
                    return "B";
                }
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == 'X') {
                    return "A";
                } else if (board[0][i] == 'O') {
                    return "B";
                }
            }
        }
        // diag
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') {
                return "A";
            } else if (board[0][0] == 'O') {
                return "B";
            }
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') {
                return "A";
            } else if (board[0][2] == 'O') {
                return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending"; 
    }
};