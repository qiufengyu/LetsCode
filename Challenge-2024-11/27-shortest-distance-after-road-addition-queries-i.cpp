#include "../header.h"

class Solution {
    int bfs(unordered_map<int, vector<int>>& graph, int n) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        int d = 0;
        while (!q.empty()) {
            d++;
            int sz = q.size();
            while (sz) {
                int tp = q.front();
                q.pop();
                for (int i = 0; i < graph[tp].size(); i++) {
                    if (graph[tp][i] == n - 1) {
                        return d;
                    }
                    if (!visited[graph[tp][i]]) {
                        visited[graph[tp][i]] = true;
                        q.push(graph[tp][i]);
                    }
                }
                sz--;
            }            
        }
        return d;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            graph[i] = {i + 1};
        }
        for (int i = 0; i < queries.size(); i++) {
            int f = queries[i][0], t = queries[i][1];
            graph[f].push_back(t);
            res.push_back(bfs(graph, n));
        }
        return res;        
    }
};

int main() {
    int n = 5;
    vector<vector<int>> queries{{2,4}, {0,2}, {0,4}};
    auto res = Solution().shortestDistanceAfterQueries(n, queries);
    return 0;
}