#include "../header.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<int> path;           
        dfs(graph, path, res, 0);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res, int node) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            res.push_back(path);
        }
        for (int i = 0; i < graph[node].size(); ++i) {
            dfs(graph, path, res, graph[node][i]);
        }
        path.pop_back();
    }
};

int main() {
    vector<vector<int>> graph {{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> res = Solution().allPathsSourceTarget(graph);
    print_vector<int>(res);
    return 0;
}