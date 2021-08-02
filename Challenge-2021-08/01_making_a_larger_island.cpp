#include "../header.h"

const int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int res = 0;
        int color = 1;
        unordered_map<int, int> areas;
        int m = grid.size(), n = grid[0].size();  
        int current = 0;  
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    color++;
                    current = 0;
                    helper(grid, current, m, n, i, j, color);
                    areas[color] = current;
                    res = max(res, areas[color]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    set<int> cs;
                    for (int d = 0; d < 4; ++d) {                        
                        cs.insert(getColor(grid, i + directions[d][0], j + directions[d][1], m, n));
                    }
                    for (auto const x: cs) {
                        area += areas[x];
                    }
                    res = max(area, res);
                }
            }
        }
        return res;      
    }

    int getColor(vector<vector<int>>& grid, int i, int j, const int m, const int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return grid[i][j];
        }
        return 0;
    }

    // int getArea(vector<vector<int>>& grid, const int m, const int n, int i, int j, const int color) {
    //     if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
    //         grid[i][j] = color;
    //         return 1 + getArea(grid, m, n, i - 1, j, color) + getArea(grid, m, n, i + 1, j, color) +
    //             getArea(grid, m, n, i, j - 1, color) + getArea(grid, m, n, i, j + 1, color);
    //     }
    //     return 0;
    // }
    
    void helper(vector<vector<int>>& grid, int& current, const int m, const int n, int i, int j, int color) {
        grid[i][j] = color;
        current++;
        for (int d = 0; d < 4; ++d) {
            int x = i + directions[d][0], y = j + directions[d][1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {               
                helper(grid, current, m, n, x, y, color);
            }
        }
    }
};

int main() {
    vector<vector<int>> grid {{1,1}, {1,0}};
    cout << Solution().largestIsland(grid) << endl;
    return 0;
}