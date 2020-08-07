#include "header.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int length = word.length();
        if (m == 0) {
            return false;
        }
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, visited, word, 0, length, m, n, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, const string word, int index, const int length, const int m, const int n, int i, int j) {
        if (index == length) {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if (visited[i][j]) {
            return false;
        } else {
            if (board[i][j] == word[index]) {
                visited[i][j] = true;
                if (helper(board, visited, word, index+1, length, m, n, i + 1, j) || 
                    helper(board, visited, word, index+1, length, m, n, i - 1, j) ||
                    helper(board, visited, word, index+1, length, m, n, i, j + 1) ||
                    helper(board, visited, word, index+1, length, m, n, i, j - 1)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;        
    }
};

int main() {
    vector<vector<char>> board {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string w;
    cin >> w;
    cout << Solution().exist(board, w) << endl;
    return 0;
}