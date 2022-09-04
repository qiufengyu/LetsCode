#include "../header.h"

int const dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pacific[0][j] = true;
            atlantic[m-1][j] = true;
        }
        vector<bool> visited(m * n, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::fill(visited.begin(), visited.end(), false);
                pacific[i][j] = pacific[i][j] || dfs(heights, i, j, visited, pacific, m, n);
                std::fill(visited.begin(), visited.end(), false);
                atlantic[i][j] = atlantic[i][j] || dfs(heights, i, j, visited, atlantic, m, n);
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }            
        }
        return res;
    }

    bool dfs(vector<vector<int>>& heights, int i, int j, vector<bool>& visited, vector<vector<bool>>& ocean, int m, int n) {
        visited[i * n + j] = true;
        if (ocean[i][j]) {
            return true;
        }
        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d][0];
            int y = j + dirs[d][1];
            if (x >= 0 && y >= 0 && x < m && y < n && (!visited[x * n + y]) && heights[i][j] >= heights[x][y]) {
                if (dfs(heights, x, y, visited, ocean, m, n)) {
                    ocean[x][y]= true;
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> heights {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = Solution().pacificAtlantic(heights);
    print_vector<int>(res);
    return 0;
}