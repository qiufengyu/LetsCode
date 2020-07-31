#include "../header.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        helper(graph, 0, {}, res);
        return res;
    }

    void helper(vector<vector<int>> &graph, int current, vector<int> path, vector<vector<int>> &res) {
        path.push_back(current);
        if (current == graph.size() - 1) {
            res.push_back(path);
        } else {
            for (int next: graph[current]) {
                helper(graph, next, path, res);
            }
        }
    }
};