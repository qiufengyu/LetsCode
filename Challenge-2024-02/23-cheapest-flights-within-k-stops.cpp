#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<PII>> graph(n);
        vector<int> cost(n, INT_MAX);
        for (auto const& f: flights) {
            int s = f[0], d = f[1], c = f[2];
            graph[s].push_back({d, c});
        }
        queue<int> q;
        q.push(src);
        cost[src] = 0;
        while (k >= 0) {
            int sz = q.size();
            vector<int> costBack = cost;
            while (sz) {
                int frt = q.front(), srcCost = costBack[frt];
                q.pop();
                for (auto& p: graph[frt]) {
                    if (cost[p.first] > srcCost + p.second) {
                        cost[p.first] = srcCost + p.second;
                        q.push(p.first);
                    }
                }
                sz--;
            }
            k--;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};