#include "../header.h"

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1)       {
            return 0;
        }
        int n = graph.size();
        int ending = (1 << n) - 1;
        vector<vector<bool>> seen(n, vector<bool>(ending, false));
        vector<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push_back({i, (1 << i)});
            seen[i][1 << i] = true;
        }
        int res = 0;
        while (!q.empty()) {
            vector<pair<int, int>> nq;
            for (int i = 0; i < q.size(); ++i) {
                pair<int, int> current = q[i];
                int node = current.first, mask = current.second;
                for (int neighbor: graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    if (nextMask == ending) {
                        return 1 + res;
                    }
                    if (!seen[neighbor][nextMask]) {
                        nq.push_back({neighbor, nextMask});
                        seen[neighbor][nextMask] = true;
                    }
                }
            }
            ++res;
            q = nq;
        }
        return -1;
    }
};