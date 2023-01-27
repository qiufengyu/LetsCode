#include "../header.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0, visited, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string word, int index, vector<vector<bool>>& visited, int m, int n) {
        if (index >= word.size()) {
            return true;
        }
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
            return false;
        }
        if (x >= 0 && y >= 0 && x < m && y < n) {
            if (word[index] == board[x][y]) {
                visited[x][y] = true;
                if (dfs(board, x + 1, y, word, index + 1, visited, m, n) ||
                    dfs(board, x - 1, y, word, index + 1, visited, m, n) ||
                    dfs(board, x, y - 1, word, index + 1, visited, m, n) ||
                    dfs(board, x, y + 1, word, index + 1, visited, m, n) ) {
                        return true;
                }
                visited[x][y] = false;
            }
        }
        return false;        
    }
};