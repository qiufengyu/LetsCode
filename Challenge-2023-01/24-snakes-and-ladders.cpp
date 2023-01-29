#include "../header.h"

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), index = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int r = n - 1; r >= 0; --r) {
            for (int c: columns) {
                cells[index] = {r, c};
                index++;
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> visited(n*n+1, false);
        visited[1] = true;
        queue<int> q;
        q.push(1);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int cur = q.front();
                q.pop();
                if (cur == n*n) {
                    return res;
                }
                for (int i = cur + 1; i <= min(cur+6, n*n); ++i){                    
                    auto [r, c] = cells[i];
                    int d = i;
                    if (board[r][c] != -1) {
                        d = board[r][c];
                    }
                    if (!visited[d]) {
                        q.push(d);
                        visited[d] = true;
                    }                                   
                }
                --sz;
            }
            ++res;
        }
        return visited[n*n] ? res : -1;
    }
};

int main() {
    vector<vector<int>> board = {{1,1,-1},{1,1,1},{-1,1,1}};
    int res = Solution().snakesAndLadders(board);
    cout << res << endl;
    return 0;
}