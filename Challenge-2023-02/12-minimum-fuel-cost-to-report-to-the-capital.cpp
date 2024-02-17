#include "../header.h"

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long res = 0;
        int n = roads.size() + 1;
        unordered_map<int, vector<int>> graph;
        for (auto const& road: roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        dfs(graph, seats, res, -1, 0);
        return res;
    }

    int dfs(unordered_map<int, vector<int>>& graph, int seats, long long& res, int u, int v) {
        int p = 1;
        for (auto const& n: graph[v]) {
            if (u != n) {
                p += dfs(graph, seats, res, v, n);
            }
        }
        if (v > 0) {
            res += ceil((double)p / seats);
        }
        return p;
    }
};