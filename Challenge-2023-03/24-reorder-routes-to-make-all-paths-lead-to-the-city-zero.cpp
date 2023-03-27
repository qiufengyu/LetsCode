#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<PII>> graph(n);
        for (auto const& c: connections) {
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], -1});
        }
        int res = 0;
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int node = q.front();
                q.pop();
                for (auto const& p: graph[node]) {
                    if (!visited[p.first]) {
                        if (p.second > 0) {
                            ++res;
                        }
                        visited[p.first] = true;
                        q.push(p.first);
                    }
                }
                --sz;
            }
        }
        return res;
    }
};