#include "../header.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for (int neighbor: graph[t]) {
                        if (color[neighbor] == color[t]) {
                            return false;
                        }
                        if (color[neighbor] == 0) {
                            color[neighbor] = -1 * color[t];
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return true;        
    }
};