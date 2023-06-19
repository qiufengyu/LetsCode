#include "../header.h"

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        // all rows into a map
        unordered_map<string, int> m;
        for (int i = 0; i < n; ++i) {
            stringstream ss;
            for (auto x: grid[i]) {
                ss << x << ",";
            }
            cout << ss.str() << endl;
            ++m[ss.str()];
        }
        // all cols in the grid
        for (int i = 0; i < n; ++i) {
            stringstream ss;
            for (int j = 0; j < n; ++j) {
                ss << grid[j][i] << ",";
            }
            res += m[ss.str()];
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid {{3,2,1},{1,7,6},{2,7,7}};
    cout << Solution().equalPairs(grid) << endl;
    return 0;
}