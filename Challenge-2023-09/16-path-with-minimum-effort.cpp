#include "../header.h"

typedef pair<int, pair<int, int>> PIPII;

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct cmp {
    bool operator()(const PIPII& a, const PIPII& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> v(m, vector<int>(n, INT_MAX));
        v[0][0] = 0;
        priority_queue<PIPII, vector<PIPII>, cmp> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int e = tp.first, x = tp.second.first, y = tp.second.second;
            if (x == m - 1 && y == n - 1) {
                return e;
            }
            for (int d = 0; d < 4; d++) {
                int dx = x + dirs[d][0], dy = y + dirs[d][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    int ne = max(e, abs(heights[x][y] - heights[dx][dy]));
                    if (ne < v[dx][dy]) {
                        v[dx][dy] = ne;
                        pq.push({ne, {dx, dy}});
                    }
                }
            }
        }
        return v[m-1][n-1];
    }
};