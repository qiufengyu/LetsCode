#include "../header.h"

class Solution {
    void dfs(vector<int>& edges, unordered_map<int, int>& dist, vector<bool>& visited, int node, int& res) {
        visited[node] = true;
        int next = edges[node];
        if (next != -1) {
            if(!visited[next]) {
                dist[next] = 1 + dist[node];
                dfs(edges, dist, visited, next, res);
            } else {
                // next can be visited in another path/cycle
                if (dist.count(next)) {
                    res = max(res, dist[node] - dist[next] + 1);
                }                
            }
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int res = -1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(edges, dist, visited, i, res);
            }
        }
        return res;
    }
};