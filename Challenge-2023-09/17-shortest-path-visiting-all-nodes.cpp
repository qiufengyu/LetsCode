#include "../header.h"

typedef pair<int, pair<int, int>> PIPII;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<PIPII> q;
        unordered_set<int> visited;
        int allVisited = (1 << n) - 1;
        for (int i = 0; i < n; ++i) {
            q.push({1 << i, {i, 0}});
            visited.insert((1 << i) * 16 + i);
        }
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            int mask = tp.first, node = tp.second.first, dist = tp.second.second;
            if (mask == allVisited) {
                return dist;
            }
            for (int nbr: graph[node]) {
                int newMask = mask | (1 << nbr);
                int visitedValue = newMask * 16 + nbr;
                if (visited.count(visitedValue) == 0) {
                    visited.insert(visitedValue);
                    q.push({newMask, {nbr, dist+1}});
                }
            }
        }
        return -1;
    }
};
