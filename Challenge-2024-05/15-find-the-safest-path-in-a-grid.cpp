#include "../header.h"

int const dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

typedef pair<int, int> PII;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return 0;
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        bfs(grid, dist, n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<pair<int, PII>> pq;
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()) {
            auto tp = pq.top();
            int safe = tp.first;
            PII tmp = tp.second;
            pq.pop();
            if (tmp.first == n - 1 && tmp.second == n - 1) {
                return safe;
            }
            visited[tmp.first][tmp.second] = true;
            for (int i = 0; i < 4; i++) {
                int x = tmp.first + dirs[i][0], y = tmp.second + dirs[i][1];
                if (x >= 0 && x < n && y >= 0 && y < n && (!visited[x][y])) {
                    int s = min(safe, dist[x][y]);
                    pq.push({s, {x, y}});
                    visited[x][y] = true;
                }
            }
        }
        return -1;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dist, int const n) {
        queue<PII> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            PII frt = q.front();
            q.pop();
            int x = frt.first, y = frt.second;
            int d = dist[x][y];
            for (int i = 0; i < 4; i++) {
                int xx = x + dirs[i][0], yy = y + dirs[i][1];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && dist[xx][yy] > 1 + d) {
                    dist[xx][yy] = 1 + d;
                    q.push({xx, yy});
                }
            }
        }
    }
};