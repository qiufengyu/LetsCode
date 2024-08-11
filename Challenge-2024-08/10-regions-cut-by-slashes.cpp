#include "../header.h"

int const dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(n * 3, vector<int>(n * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    graph[i*3][j*3+2] = 1;
                    graph[i*3+1][j*3+1] = 1;
                    graph[i*3+2][j*3] = 1;
                } else if (grid[i][j] == '\\') {
                    graph[i*3][j*3] = 1;
                    graph[i*3+1][j*3+1] = 1;
                    graph[i*3+2][j*3+2] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (graph[i][j] == 0) {
                    res++;
                    dfs(graph, i, j, 3 * n);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& graph, int i, int j, int const n) {
        graph[i][j] = 1;
        for (int d = 0; d < 4; d++) {
            int x = dirs[d][0] + i, y = dirs[d][1] + j;
            if (x >= 0 && y >= 0 && x < n && y < n && graph[x][y] == 0) {
                dfs(graph, x, y, n);
            }
        }
    }
};