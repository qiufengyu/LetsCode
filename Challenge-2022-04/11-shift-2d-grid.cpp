#include "../header.h"

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int mn = m * n;
        vector<vector<int>> res(m, vector<int>(n, 0));
        k = k % mn;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j + k) % mn;
                int x = idx / n, y = idx % n;
                res[x][y] = grid[i][j];
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    int k = 4;
    vector<vector<int>> res = Solution().shiftGrid(grid, k);
    print_vector<int>(res);
    return 0;
}