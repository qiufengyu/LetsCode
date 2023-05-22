#include "../header.h"


class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int, int>> n1, n2;
        bool first = true;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && first) {
                    first = false;
                    dfs(grid, m, n, i, j, n1);
                } else if (grid[i][j] == 1) {
                    dfs(grid, m, n, i, j, n2);
                }
            }
        }
        int res = INT_MAX;
        for (auto const &p1: n1) {
            for (auto const &p2: n2) {
                res = min(res, abs(p1.first-p2.first) + abs(p1.second-p2.second) - 1);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int const m, int const n, int i, int j, set<pair<int, int>>& st) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        st.insert({i, j});
        grid[i][j] = 0;
        dfs(grid, m, n, i + 1, j, st);
        dfs(grid, m, n, i - 1, j, st);
        dfs(grid, m, n, i, j + 1, st);
        dfs(grid, m, n, i, j - 1, st);
    }
};

int main() {
    vector<vector<int>> grid {{0,1},{1,0}};
    cout << Solution().shortestBridge(grid) << endl;
    return 0;
}