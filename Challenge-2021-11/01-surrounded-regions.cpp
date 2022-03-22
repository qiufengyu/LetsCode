#include "../header.h"

const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
    void dfsFill(vector<vector<char>>& board, const int m, const int n, int i, int j, set<pair<int, int>>& outer) {
        outer.emplace(i, j);
        if (board[i][j] == 'O') {
            for (int d = 0; d < 4; ++d) {
                int x = i + directions[d][0], y = j + directions[d][1];
                if (x >= 0 && x < m && y >= 0 && y < n && outer.count({x, y}) == 0) {
                    dfsFill(board, m,n , x, y, outer);
                } 
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        set<pair<int, int>> outer;
        for (int i = 0; i < n; ++i) {
            dfsFill(board, m, n, 0, i, outer);
            dfsFill(board, m, n, m - 1, i, outer);
        }
        for (int i = 1; i < m - 1; ++i) {
            dfsFill(board, m, n, i, 0, outer);
            dfsFill(board, m, n, i, n - 1, outer);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && outer.count({i, j}) == 0) {
                    board[i][j] = 'X';
                }
            }
        }        
    }
};

int main() {
    vector<vector<char>> board {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution().solve(board);
    print_vector<char>(board);
    return 0;
}