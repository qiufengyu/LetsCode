#include "../header.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> connect(n, 0);
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (auto const& r: roads) {
            connect[r[0]]++;
            connect[r[1]]++;
            graph[r[0]][r[1]] = 1;
            graph[r[1]][r[0]] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = connect[i] + connect[j];
                if (graph[i][j]) {
                    rank--;
                }
                res = max(res, rank);
            }
        }
        return res;
    }
};