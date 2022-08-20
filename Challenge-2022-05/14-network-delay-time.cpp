#include "../header.h"

typedef pair<int, int> nw;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<nw>> graph(n + 1);
        for (const auto& time: times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        // Dijkstra
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;
        // in pq, first: weight, second: node
        priority_queue<nw, vector<nw>, greater<nw>> pq;
        pq.push({0, k});
        int u, v, w;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            u = t.second;
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            for (const auto& to: graph[u]) {
                v = to.first;
                w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }            
        }
        // count from 1
        int res = *max_element(dist.begin() + 1, dist.end());
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
    
};