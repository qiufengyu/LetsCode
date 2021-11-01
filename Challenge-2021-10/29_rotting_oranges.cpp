#include "../header.h"

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> rotted;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 2) {
                        for (int t = 0; t < 4; ++t) {
                            int x = i + d[t][0], y = j + d[t][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                flag = true;
                                rotted.push_back({x, y});
                            }
                        }
                    }
                }
            }
            for (auto const& p: rotted) {
                grid[p.first][p.second] = 2;
            }
            rotted.clear();
            if (flag) {
                ++res;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;        
    }
};

int main() {
    vector<vector<int>> grid {{2,1,1},{1,1,0},{0,1,1}};
    cout << Solution().orangesRotting(grid) << endl;
    return 0;
}