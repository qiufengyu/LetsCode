#include "../header.h"

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int servers = 0;
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                servers += grid[i][j];
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            if (rows[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && cols[j] == 1) {
                        servers--;
                    }
                }    
            }               
        }
        return servers;
    }
};