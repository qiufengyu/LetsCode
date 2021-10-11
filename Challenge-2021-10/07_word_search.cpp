#include "../header.h"

class Solution {
public:    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int length = word.length();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, visited, word, 0, length, m, n, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const string word, int index, const int length, const int m, const int n, int i, int j) {
        if (index == length) {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
            return false;
        }        
        if (board[i][j] == word[index]) {
            visited[i][j] = true;
            if (dfs(board, visited, word, index+1, length, m, n, i + 1, j) || 
                dfs(board, visited, word, index+1, length, m, n, i - 1, j) ||
                dfs(board, visited, word, index+1, length, m, n, i, j + 1) ||
                dfs(board, visited, word, index+1, length, m, n, i, j - 1)) {
                return true;
            }                
            visited[i][j] = false;
        }        
        return false;
    }
};