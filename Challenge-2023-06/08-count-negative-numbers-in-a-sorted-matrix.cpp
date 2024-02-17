#include "../header.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = 0, j = n - 1, res = 0;
        while (i < m && j >= 0) {
            if (grid[i][j] < 0) {
                --j;
            } else {
                res += (n - 1 - j);
                ++i;
            }
        }
        // special cases when there are still some rows left
        if (j < 0) {
            res += (n * (m - i));
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout << Solution().countNegatives(grid) << endl;
    return 0;
}