#include "../header.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bool changed = true;
        bool fresh = false;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> prev (m, vector<int>(n, 0));
        while (changed) {
            changed = false;
            fresh = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    prev[i][j] = grid[i][j];                    
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        if (i-1 >= 0 && prev[i-1][j] == 2) {
                            grid[i][j] = 2;
                            changed = true;
                        }
                        if (i+1 < m && prev[i+1][j] == 2) {
                            grid[i][j] = 2;
                            changed = true;
                        }
                        if (j-1>= 0 && prev[i][j-1] == 2) {
                            grid[i][j] = 2;
                            changed = true;
                        }
                        if (j+1 < n && prev[i][j+1] == 2) {
                            grid[i][j] = 2;
                            changed = true;
                        }
                    }
                    if (grid[i][j] == 1) {
                        fresh = true;
                    }
                }
            }
            if (changed) {
                res++;
            }
        }
        return fresh ? -1 : res;
    }
};

int main() {
    vector<vector<int>> grid {{0,2}};
    cout << Solution().orangesRotting(grid) << endl;
    return 0;
}