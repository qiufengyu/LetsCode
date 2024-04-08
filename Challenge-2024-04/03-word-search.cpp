#include "../header.h"

typedef pair<int, int> PII;

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    visited[i][j] = true;
                    if (helper(board, visited, 1, word, {i, j}, m, n)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& b, vector<vector<bool>>& v, int index, string const& word, PII ij, int m, int n) {
        if (index >= word.size()) {
            return true;
        }
        for (int d = 0; d < 4; d++) {
            int x = ij.first + dirs[d][0], y = ij.second + dirs[d][1];
            if (x >= 0 && y >= 0 && x < m && y < n && !v[x][y]) {
                if (word[index] == b[x][y]) {
                    v[x][y] = true;
                    if (helper(b, v, index+1, word, {x, y}, m, n)) {
                        return true;
                    }
                    v[x][y] = false;
                }                
            }
        }
        return false;
    }
};