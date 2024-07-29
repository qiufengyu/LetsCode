#include "../header.h"

typedef pair<int, int> PII;

class Solution {
    inline static int helper(int step, const int time, const int change) {
        int res = 0;
        for (int i = 0; i < step; i++) {
            int green = res / change;
            if (green % 2 == 1) {
                res = (green + 1) * change;
            }
            res += time;
        }
        return res;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (auto const& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> dist1(n+1, INT_MAX), dist2(n+1, INT_MAX);
        queue<PII> q;
        q.push({1, 0});
        dist1[1] = 0;
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int node = f.first, dist = f.second;
            for (int nbr: graph[node]) {
                int newDist = dist + 1;
                if (newDist < dist1[nbr]) {
                    dist2[nbr] = dist1[nbr];
                    dist1[nbr] = newDist;
                    q.push({nbr, newDist});
                } else if (newDist > dist1[nbr] && newDist < dist2[nbr]) {
                    dist2[nbr] = newDist;
                    q.push({nbr, newDist});
                }
            }
        }
        int steps = dist2[n];
        if (steps == INT_MAX) {
            return -1;
        }
        return helper(steps, time, change);
    }
};