#include "../header.h"

typedef pair<int, pair<int, int>> PAIR;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        const int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        efforts[0][0] = 0;
        priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
        pq.push({0, {0,0}});
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int effort = current.first, x = current.second.first, y = current.second.second;
            // cout << effort << " <- " << x << "," << y << endl;
            if (x == m - 1 && y == n - 1) {
                return effort;
            }
            for (int d = 0; d < 4; ++d) {
                int nx = x + dir[d][0], ny = y + dir[d][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nextEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if (nextEffort < efforts[nx][ny]) {
                        efforts[nx][ny] = nextEffort;
                        pq.push({nextEffort, {nx, ny}});
                        // cout << "push "  << nextEffort << " <- " << nx << "," << ny << endl;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> heights {{1,2,2},{3,8,2},{5,3,5}};
    cout << Solution().minimumEffortPath(heights) << endl;
    return 0;
}