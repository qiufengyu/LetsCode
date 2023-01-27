#include "../header.h"

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        visited[source] = true;
        unordered_map<int, vector<int>> graph;
        for (auto const& edge: edges) {
            int a = edge[0], b = edge[1];
            if (graph.find(a) == graph.end()) {
                graph[a] = {b};
            } else {
                graph[a].push_back(b);
            }
            if (graph.find(b) == graph.end()) {
                graph[b] = {a};
            } else {
                graph[b].push_back(a);
            }
        }
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int node = q.front();
                q.pop();
                visited[node] = true;
                if (node == destination) {
                    return true;
                }
                for (auto x: graph[node]) {
                    if (!visited[x]) {
                        q.push(x);
                    }
                }
                --sz;
            }
        }
        return false;
    }
};