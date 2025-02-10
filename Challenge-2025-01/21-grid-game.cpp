#include "../header.h"

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long res = LLONG_MAX;
        long long p1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long p2 = 0LL;
        for (int i = 0; i < grid[0].size(); i++) {
            p1 -= grid[0][i];
            res = min(res, max(p1, p2));
            p2 += grid[1][i];
        }
        return res;
    }
};