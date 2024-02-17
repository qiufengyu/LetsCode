#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // start from 1
        // cannot use sparse matrix to store the graph => TLE
        vector<vector<PII>> graph(n+1);
        for (auto const& road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        queue<int> q;
        vector<bool> visited(n+1, false);
        visited[1] = true;
        q.push(1);
        int res = INT_MAX;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int node = q.front();
                q.pop();
                for (auto const& edge: graph[node]) {
                    res = min(res, edge.second);
                    if (!visited[edge.first]) {
                        visited[edge.first] = true;
                        q.push(edge.first);
                    }                    
                }
                --sz;
            }
        }
        return res;
    }
};