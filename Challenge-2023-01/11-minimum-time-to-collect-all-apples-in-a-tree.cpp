#include "../header.h"

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        for (auto const& edge: edges) {
            if (graph.count(edge[0])) {
                graph[edge[0]].push_back(edge[1]);
            } else {
                graph[edge[0]] = {edge[1]};
            }
            if (graph.count(edge[1])) {
                graph[edge[1]].push_back(edge[0]);
            } else {
                graph[edge[1]] = {edge[0]};
            }
        }
        return max(0, dfs(graph, hasApple, 0, -1));
    }

    int dfs(unordered_map<int, vector<int>>& graph, vector<bool>& hasApple, int current, int parent) {
        int res = 0;
        for (int const& node: graph[current]) {
            if (node != parent) {
                res += dfs(graph, hasApple, node, current);
            }
        }
        if (current != 0 && (hasApple[current] || res != 0)) {
            res += 2;
        }
        return res;
    }
};