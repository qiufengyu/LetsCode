#include "../header.h"

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) {
            return -1;
        }
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (auto const& c: connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        int part = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                part++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int sz = q.size();
                    while (sz > 0) {
                        int c = q.front();
                        q.pop();
                        for (auto const t: graph[c]) {
                            if (!visited[t]) {
                                visited[t] = true;
                                q.push(t);
                            }
                        }
                        --sz;
                    }
                }
            }
        }
        return part - 1;
    }
};