#include "../header.h"

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> graph;
        vector<int> res(n, 0);
        vector<int> count(26, 0);
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
        dfs(graph, labels, 0, -1, res, count);
        return res;
    }

    void dfs(unordered_map<int, vector<int>>& graph, string labels, int current, int parent, vector<int>& res, vector<int>& count) {
        for (int const& node: graph[current]) {
            if (node != parent) {
                vector<int> c(26, 0);
                dfs(graph, labels, node, current, res, count);
                for (int i = 0; i < 26; ++i) {
                    count[i] += c[i];
                }
            }
        }
        count[labels[current] - 'a']++;
        res[current] = count[labels[current]-'a'];        
    }
};